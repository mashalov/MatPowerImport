#include <complex>
#include <map>
#include <array>
#include "RastrWinIO.h"

std::filesystem::path RastrWinIO::RastrWinDB::GetTemplatesPath()
{
	std::filesystem::path path;
	HKEY rastrkey;
	if (RegOpenKey(HKEY_CURRENT_USER, "Software\\RastrWin3", &rastrkey) == ERROR_SUCCESS)
	{
		DWORD Count{ 0 }, Type { 0 };
		if (RegQueryValueExA(rastrkey, "UserFolder", NULL, &Type, NULL, &Count) == ERROR_SUCCESS && Type == REG_SZ)
		{
			auto pathbuffer{ std::make_unique<char[]>(static_cast<size_t>(Count) + 1)};

			if (RegQueryValueExA(rastrkey, "UserFolder", NULL, &Type, reinterpret_cast<LPBYTE>(pathbuffer.get()), &Count) == ERROR_SUCCESS)
				path.assign(pathbuffer.get());
		}
		RegCloseKey(rastrkey);
	}

	if (!path.empty())
		path /= "Shablon"; 
	return path;
}

void RastrWinIO::Import(MatPowerCase& data, const std::filesystem::path& path)
{
	try
	{
		db.rastr->Load(ASTRALib::RG_REPL, 
					   stringutils::COM_encode(path.string()).c_str(), 
					   stringutils::COM_encode(db.rg2template.string()).c_str());
		db.Init();

		data.buses.clear();
		data.buses.reserve(db.nodes->GetSize());
		long size{ db.nodes->GetSize() };

		data.comment_ = fmt::format("Exported from RastrWin {}\n% https://github.com/mashalov/MatPowerImport", path.filename().string());

		std::map<long, long> NodeMap, GenMap;

		struct PVnode
		{
			long Id;
			double Vref;
			double Qmin;
			double Qmax;
			double Pg;
			double Qg;
		};

		std::list<PVnode> pvnodes;

		for (long row{ 0 }; row < size ; row++)
		{
			data.buses.push_back({});
			auto& bus{ data.buses.back() };
			bus.Id = db.nodeId->GetZ(row).lVal;
			bus.Unom = db.nodeUnom->GetZN(row).dblVal;
			if(bus.Unom <= 0.0)
				data.logger_.Log(LogMessageTypes::Error, "Bus {} has wrong Unom {}", bus.Id, bus.Unom);

			bus.Pn = db.nodePnr->GetZN(row).dblVal;
			bus.Qn = db.nodeQnr->GetZN(row).dblVal;
			bus.V = db.nodeV->GetZN(row).dblVal / bus.Unom;
			bus.Delta = db.nodeDelta->GetZN(row).dblVal;
			bus.AreaId = db.nodeArea->GetZ(row).lVal;
			bus.Gsh = db.nodeGshr->GetZ(row).dblVal * bus.Unom * bus.Unom;
			bus.Bsh = -db.nodeBshr->GetZ(row).dblVal * bus.Unom * bus.Unom;
			bus.Name = db.nodeName->GetZS(row);
			bus.Type = 1;

						
			if (db.nodeState->GetZ(row).lVal)
				bus.Type = 4;
			else
			{
				switch (db.nodeType->GetZ(row).lVal)
				{
				case 2:
				case 3:
				case 4:
					bus.Type = 2;
					break;
				case 0:
					bus.Type = 3;
				}
			}

			NodeMap.insert({ bus.Id, row });

			PVnode  pvnode;
			pvnode.Id = bus.Id;
			pvnode.Pg = db.nodePgr->GetZN(row).dblVal;
			pvnode.Qg = db.nodeQgr->GetZN(row).dblVal;
			pvnode.Qmin = db.nodeQmin->GetZN(row).dblVal;
			pvnode.Qmax = db.nodeQmax->GetZN(row).dblVal;
			pvnode.Vref = db.nodeVref->GetZN(row).dblVal / db.nodeUnom->GetZN(row).dblVal;

			if (std::abs(pvnode.Pg) > 1e-7 || std::abs(pvnode.Qg) > 1e-7 ||
				pvnode.Vref > 0.0)
				pvnodes.push_back(pvnode);
		}


		size = db.branches->GetSize();
		data.branches.reserve(size);

		for (long row{ 0 }; row < size; row++)
		{
			data.branches.push_back({});
			auto& branch{ data.branches.back() };
			branch.IdHead = db.branchHead->GetZ(row).lVal;
			branch.IdTail = db.branchTail->GetZ(row).lVal;


			struct NodeIndex
			{
				long Id;
				decltype(NodeMap)::const_iterator it;
			};

			std::array< NodeIndex, 2 > ht{ {{ branch.IdHead, NodeMap.end() } , { branch.IdTail, NodeMap.end() } } };

			for (auto&& node : ht)
				if (node.it = NodeMap.find(node.Id); node.it == NodeMap.end())
					data.logger_.Log(LogMessageTypes::Error, cszBranchWrongNode, branch.IdHead, branch.IdTail, node.Id);

			if (ht[0].it != NodeMap.end() && ht[1].it != NodeMap.end())
			{
				auto& HeadNode{ data.buses[ht[0].it->second] };
				auto& TailNode{ data.buses[ht[1].it->second] };
			
				const auto UHnom{ HeadNode.Unom };
				const auto UTnom{ TailNode.Unom };

				std::complex<double> kt{ db.branchktr->GetZN(row).dblVal, db.branchkti->GetZN(row).dblVal };
				if (std::abs(kt.real()) < 1e-7)
					kt.real(1.0);

				kt = UTnom / UHnom / kt;

				branch.State = db.branchsta->GetZ(row).lVal ? 0 : 1;

				auto ZbaseHead{ UHnom * UHnom * std::norm(kt) / data.BaseMVA_ };
				auto ZbaseTail{ UTnom * UTnom / data.BaseMVA_ };

				branch.r = db.branchr->GetZN(row).dblVal / ZbaseHead;
				branch.x = db.branchx->GetZN(row).dblVal / ZbaseHead;
				double bip{ -db.branchbip->GetZ(row).dblVal };
				double biq{ -db.branchbiq->GetZ(row).dblVal };
				double gip{ db.branchgip->GetZ(row).dblVal };
				double giq{ db.branchgiq->GetZ(row).dblVal };
				
				if (branch.State)
				{
					HeadNode.Gsh += gip * UHnom * UHnom;
					TailNode.Gsh += giq * UTnom * UTnom;
				}

				if(std::abs(bip - biq) < 1e-7)
					branch.b = (bip + biq) * ZbaseHead;
				else if(branch.State)
				{
					HeadNode.Bsh += bip * UHnom * UHnom;
					TailNode.Bsh += biq * UTnom * UTnom;
				}

				branch.ktr = std::abs(kt);
				branch.kti = std::arg(kt) * 180.0 / pi;
			}
		}

		size = db.generators->GetSize();
		data.generators.reserve(pvnodes.size());

		for (long row{ 0 }; row < size; row++)
		{
			data.generators.push_back({});
			auto& gen{ data.generators.back() };
			gen.Id = db.genBus->GetZ(row).lVal;

			GenMap.insert({ gen.Id, row });

			gen.Pg = db.genPg->GetZN(row).dblVal;
			gen.Qg = db.genQg->GetZN(row).dblVal;
			gen.State = db.genState->GetZ(row).lVal ? 0 : 1;

			double Qmin{ db.genQmin->GetZN(row).dblVal };
			double Qmax{ db.genQmax->GetZN(row).dblVal };
			// handling of RastrWin [0;0] limits is ambiguous
			//if (std::abs(Qmax - Qmin) < 1e-7 && std::abs(Qmax) < 1e-7)  { Qmin = -1e6;	Qmax = 1e6; }
			gen.Qmin = Qmin;
			gen.Qmax = Qmax;

			gen.Pmin = db.genPmin->GetZ(row).dblVal;
			gen.Pmax = db.genPmax->GetZ(row).dblVal;

			if (auto Node{ NodeMap.find(gen.Id) }; Node == NodeMap.end())
				throw CException(cszGeneratorWrongNode, row + 1, gen.Id);
			else
				gen.Vg = db.nodeVref->GetZN(Node->second).dblVal / data.buses[Node->second].Unom;
		}

		for (const auto& pvnode : pvnodes)
		{
			if (GenMap.find(pvnode.Id) == GenMap.end())
			{
				auto& node{ data.buses[NodeMap.find(pvnode.Id)->second] };
				// RastrWin node has Vref and it must be supplied by generator
				if (pvnode.Vref > 0)
				{
					data.generators.push_back({});
					auto& gen{ data.generators.back() };
					gen.Id = pvnode.Id;
					gen.Vg = pvnode.Vref;
					gen.Qmin = pvnode.Qmin;
					gen.Qmax = pvnode.Qmax;
					gen.Pg = pvnode.Pg;
					gen.Qg = pvnode.Qg;
					gen.State = (node.Type == 4) ? 0 : 1;
				}
				else
				{
					// Vref is not set, just account generation as neagative load
					node.Pn -= pvnode.Pg;
					node.Qn -= pvnode.Qg;
				}
			}
		}

		if (!data.Silent())
			data.logger_.Log(LogMessageTypes::Info, "RastrWin model is imported from {}", path.string());
	}

	catch (const _com_error& ex)
	{
		throw CException("RastrWin error: {}", stringutils::COM_decode(ex.Description()));
	}
}

void RastrWinIO::Export(const MatPowerCase& data, const std::filesystem::path& path)
{
	try
	{
		long row{ 0 };
		db.Init();
		db.nodes->PutSize(static_cast<long>(data.buses.size()));
		db.rastr->LockEvent = true;

		std::map<long, long> NodeMap;
		for (const auto& node : data.buses)
		{
			NodeMap.insert({ node.Id, row });
			db.nodeId->PutZN(row, node.Id);
			db.nodeUnom->PutZN(row, node.Unom);
			db.nodePn->PutZN(row, node.Pn);
			db.nodeQn->PutZN(row, node.Qn);
			db.nodeType->PutZ(row, 1);
			db.nodeV->PutZN(row, node.V * node.Unom);
			db.nodeDelta->PutZN(row, node.Delta);
			db.nodeArea->PutZ(row, node.AreaId);
			db.nodeGsh->PutZ(row, node.Gsh / node.Unom / node.Unom);
			db.nodeBsh->PutZ(row, -node.Bsh / node.Unom / node.Unom);
			db.nodeName->PutZS(row, node.Name.c_str());

			switch (node.Type)
			{
			case 2:
				db.nodeType->PutZ(row, 2);
				break;
			case 3:
				db.nodeType->PutZ(row, 0);
				break;
			case 4:
				db.nodeState->PutZ(row, true);
				break;
			}

			row++;
		}

		row = 0;
		db.branches->PutSize(static_cast<long>(data.branches.size()));


		constexpr const char* yes = "yes";
		constexpr const char* no = "no";

		if (!StatsOnly())
		{
			data.logger_.Log(LogMessageTypes::Info, "Transformer invert angle: {}", InvertTransformerAngle() ? yes : no);
			data.logger_.Log(LogMessageTypes::Info, "Zbase optional: {}", UseOptionalZbase() ? yes : no);
		}

		for (const auto& branch : data.branches)
		{
			db.branchHead->PutZ(row, branch.IdHead);
			db.branchTail->PutZ(row, branch.IdTail);

			struct NodeIndex
			{
				long Id;
				decltype(NodeMap)::const_iterator it;
			};

			std::array< NodeIndex, 2 > ht{ {{ branch.IdHead, NodeMap.end() } , { branch.IdTail, NodeMap.end() } } };

			for (auto&& node : ht)
				if (node.it = NodeMap.find(node.Id); node.it == NodeMap.end())
					data.logger_.Log(LogMessageTypes::Error, cszBranchWrongNode, branch.IdHead, branch.IdTail, node.Id);

			if (ht[0].it != NodeMap.end() && ht[1].it != NodeMap.end())
			{
				const auto UHnom{ data.buses[ht[0].it->second].Unom };
				const auto UTnom{ data.buses[ht[1].it->second].Unom };

				// some cases goes with zero real part of ratio and nonzero angle shift
				// the sign of angle shift is enigmatic

				// the transformer angle is uncertainly defined in caseformat
				// so we have option to account it positive (default) or negative
				const double Angle{ (InvertTransformerAngle_ ? -branch.kti : branch.kti) / 180.0 * pi };
				std::complex<double> kt{ std::polar(std::abs(branch.ktr)< 1E-7 ? 1.0 : branch.ktr, Angle) };

				auto Zbase{ 1.0 / data.BaseMVA_ };

				// Zbase is also uncertain. There are two opinions 
				// on its calculation
				if (UseOptionalZbase_)
					Zbase *= UHnom * UHnom;						// alternative mode in some caseformats
				else
					Zbase *= UHnom * UHnom * std::norm(kt);		// seems to be matpower default mode
					

				kt = UTnom / UHnom / kt;
					

				// clear ratio if it is equal to 1.0 with no angle shift
				if (std::abs(kt.real() - 1.0) < 1E-5 && kt.imag() == 0)
					kt = 0.0;

				db.branchktr->PutZ(row, kt.real());
				db.branchkti->PutZ(row, kt.imag());
				db.branchr->PutZ(row, branch.r * Zbase);
				db.branchx->PutZ(row, branch.x * Zbase);
				db.branchb->PutZ(row, -branch.b / Zbase);
				db.branchsta->PutZ(row, branch.State ? 0 : 1);
			}

			row++;
		}

		row = 0;

		db.generators->PutSize(static_cast<long>(data.generators.size()));

		for (const auto& gen : data.generators)
		{
			db.genId->PutZ(row, row + 1);
			db.genBus->PutZ(row, gen.Id);
			db.genPg->PutZN(row, gen.Pg);
			db.genQg->PutZN(row, gen.Qg);

			const auto fnFixInf = [](const double  value) -> double
			{
				return std::isinf(value) ? (value > 0 ? 1e6 : -1e6) : value;
			};

			db.genQmin->PutZN(row, (fnFixInf)(gen.Qmin));
			db.genQmax->PutZN(row, (fnFixInf)(gen.Qmax));
			db.genPmin->PutZN(row, (fnFixInf)(gen.Pmin));
			db.genPmax->PutZN(row, (fnFixInf)(gen.Pmax));

			if (auto Node{ NodeMap.find(gen.Id) }; Node == NodeMap.end())
				throw CException(cszGeneratorWrongNode, row + 1, gen.Id);
			else
				db.nodeVref->PutZN(Node->second, gen.Vg * data.buses[Node->second].Unom);

			db.genState->PutZ(row, gen.State ? 0 : 1);

			row++;
		}

		row = 0;

		db.areas->PutSize(static_cast<long>(data.areas.size()));
		for (const auto& area : data.areas)
		{
			db.areaId->PutZ(row, area.Id);
			row++;
		}
				
		db.flat->PutZ(0, LoadFlowFlat() ? 1 : 0);
		db.itmax->PutZ(0, 500);
		db.removeBreakers->PutZ(0, 0);

		constexpr const char* flatmsg = "from the flat start";
		constexpr const char* noflatmsg = "from the original solution";

		if (LoadFlow())
		{
			const auto ret{ db.rastr->rgm("") };
			if (ret == ASTRALib::AST_OK)
			{
				if(!StatsOnly())
					data.logger_.Log(LogMessageTypes::Info, "Load flow solved {}", LoadFlowFlat() ? flatmsg : noflatmsg);
			}
			else
				data.logger_.Log(LogMessageTypes::Error, "Load flow failed {}", LoadFlowFlat() ? flatmsg : noflatmsg);
		}

		if (LoadFlowStats())
		{
			const auto stats{ Stats(data) };
			data.logger_.Log(LogMessageTypes::Info, "Vstd : {} Astd : {}", stats.Vstd, stats.Astd);

		}

		db.rastr->Save(stringutils::COM_encode(path.string()).c_str(), stringutils::COM_encode(db.rg2template.string()).c_str());
		if(!StatsOnly())
			data.logger_.Log(LogMessageTypes::Info, "RastrWin model is exported to {}", path.string());
	}
	catch (const _com_error& ex)
	{
		throw CException("RastrWin error: {}", stringutils::COM_decode(ex.Description()));
	}
}

RastrWinIO::LFStats RastrWinIO::Stats(const MatPowerCase& data) const
{
	RastrWinIO::LFStats stats;

	for (long row = 0; row < db.nodes->GetSize(); row++)
	{
		if (row < data.buses.size())
		{
			const auto& bus{ data.buses[row] };
			double diff{ db.nodeV->GetZ(row).dblVal - bus.V * bus.Unom };
			stats.Vstd += diff * diff;
			diff = db.nodeDelta->GetZ(row).dblVal * 180.0 / pi - bus.Delta;
			stats.Astd += diff * diff;
		}
	}

	if (db.nodes->GetSize())
	{
		stats.Vstd = std::sqrt(stats.Vstd / db.nodes->GetSize());
		stats.Astd = std::sqrt(stats.Astd / db.nodes->GetSize());
	}

	return stats;
}

RastrWinIO::RastrWinDB::RastrWinDB()
{
	CoInitialize(NULL);
	if (FAILED(rastr.CreateInstance(ASTRALib::CLSID_Rastr)))
		throw CExceptionGLE(cszRastrWinUnavailable);

	rg2template = RastrWinIO::RastrWinDB::GetTemplatesPath();
	if (rg2template.empty())
		throw CException("RastrWin template path not found");
	rg2template /= "режим.rg2";

	rastr->NewFile(stringutils::COM_encode(rg2template.string()).c_str());
}

void RastrWinIO::RastrWinDB::Init()
{
	ASTRALib::ITablesPtr tables{ rastr->Tables };
	nodes = tables->Item("node");
	branches = tables->Item("vetv");
	generators = tables->Item("Generator");
	areas = tables->Item("area");
	param = tables->Item("com_regim");


	ASTRALib::IColsPtr nodecols{ nodes->Cols };
	nodeId = nodecols->Item("ny");
	nodeUnom = nodecols->Item("uhom");
	nodePn = nodecols->Item("pn");
	nodePnr = nodecols->Item("pnr");
	nodeQn = nodecols->Item("qn");
	nodeQnr = nodecols->Item("qnr");
	nodeType = nodecols->Item("tip");
	nodeState = nodecols->Item("sta");
	nodeV = nodecols->Item("vras");
	nodeDelta = nodecols->Item("delta");
	nodeArea = nodecols->Item("na");
	nodeGsh = nodecols->Item("gsh");
	nodeBsh = nodecols->Item("bsh");
	nodeGshr = nodecols->Item("gshr");
	nodeBshr = nodecols->Item("bshr");
	nodeName =nodecols->Item("name");
	nodeVref = nodecols->Item("vzd");
	nodeQmin = nodecols->Item("qmin");
	nodeQmax = nodecols->Item("qmax");
	nodePgr = nodecols->Item("pgr");
	nodeQgr = nodecols->Item("qgr");

	ASTRALib::IColsPtr branchcols{ branches->Cols };
	branchHead = branchcols->Item("ip");
	branchTail = branchcols->Item("iq");
	branchr = branchcols->Item("r");
	branchx = branchcols->Item("x");
	branchb = branchcols->Item("b");
	branchbip = branchcols->Item("b_ip");
	branchbiq = branchcols->Item("b_iq");
	branchgip = branchcols->Item("g_ip");
	branchgiq = branchcols->Item("g_iq");
	branchktr = branchcols->Item("ktr");
	branchkti = branchcols->Item("kti");
	branchsta = branchcols->Item("sta");


	ASTRALib::IColsPtr gencols{ generators->Cols };
	genBus = gencols->Item("Node");
	genId = gencols->Item("Num");
	genState = gencols->Item("sta");
	genPg = gencols->Item("P");
	genQg = gencols->Item("Q");
	genQmin = gencols->Item("Qmin");
	genQmax = gencols->Item("Qmax");
	genPmin = gencols->Item("Pmin");
	genPmax = gencols->Item("Pmax");

	ASTRALib::IColsPtr areacols{ areas->Cols };
	areaId = areacols->Item("na");

	ASTRALib::IColsPtr paramCols{ param->Cols };
	flat = paramCols->Item("flot");
	itmax = paramCols->Item("it_max");
	removeBreakers = paramCols->Item("rem_breaker");
}
