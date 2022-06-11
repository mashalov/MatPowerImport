#include <complex>
#include <map>
#include <array>
#include "RastrWinIO.h"
#import "progid:Astra.Rastr.1" named_guids

std::filesystem::path RastrWinIO::GetTemplatesPath() const
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

void RastrWinIO::Export(const MatPowerCase& data, const std::filesystem::path& path)
{
	try
	{
		CoInitialize(NULL);
		ASTRALib::IRastrPtr rastr;
		if (FAILED(rastr.CreateInstance(ASTRALib::CLSID_Rastr)))
			throw CExceptionGLE("RastrWin unavailable");

		std::filesystem::path rg2template{ GetTemplatesPath() };
		if (rg2template.empty())
			data.logger_.Log(LogMessageTypes::Error, "RastrWin template path not found");
		rg2template /= "режим.rg2";
		rastr->NewFile(stringutils::COM_encode(rg2template.string()).c_str());
		auto tables{ rastr->Tables };
		ASTRALib::ITablePtr nodes{ tables->Item("node") };
		ASTRALib::ITablePtr branches{ tables->Item("vetv") };
		ASTRALib::ITablePtr generators{ tables->Item("Generator") };
		ASTRALib::ITablePtr areas{ tables->Item("area") };

		long row{ 0 };
		nodes->PutSize(static_cast<long>(data.buses.size()));
		ASTRALib::IColsPtr nodecols{ nodes->Cols };
		ASTRALib::IColPtr nodeId{ nodecols->Item("ny") };
		ASTRALib::IColPtr nodeUnom{ nodecols->Item("uhom") };
		ASTRALib::IColPtr nodePn{ nodecols->Item("pn") };
		ASTRALib::IColPtr nodeQn{ nodecols->Item("qn") };
		ASTRALib::IColPtr nodeType{ nodecols->Item("tip") };
		ASTRALib::IColPtr nodeState{ nodecols->Item("sta") };
		ASTRALib::IColPtr nodeV{ nodecols->Item("vras") };
		ASTRALib::IColPtr nodeDelta{ nodecols->Item("delta") };
		ASTRALib::IColPtr nodeArea{ nodecols->Item("na") };
		ASTRALib::IColPtr nodeGsh{ nodecols->Item("gsh") };
		ASTRALib::IColPtr nodeBsh{ nodecols->Item("bsh") };
		ASTRALib::IColPtr nodeVref{ nodecols->Item("vzd") };
		ASTRALib::IColPtr nodeName{ nodecols->Item("name") };

		rastr->LockEvent = true;

		std::map<long, long> NodeMap;
		for (const auto& node : data.buses)
		{
			NodeMap.insert({ node.Id, row });
			nodeId->PutZN(row, node.Id);
			nodeUnom->PutZN(row, node.Unom);
			nodePn->PutZN(row, node.Pn);
			nodeQn->PutZN(row, node.Qn);
			nodeType->PutZ(row, 1);
			nodeV->PutZN(row, node.V * node.Unom);
			nodeDelta->PutZN(row, node.Delta);
			nodeArea->PutZ(row, node.AreaId);
			nodeGsh->PutZ(row, node.Gsh / node.Unom / node.Unom);
			nodeBsh->PutZ(row, -node.Bsh / node.Unom / node.Unom);
			nodeName->PutZS(row, node.Name.c_str());

			switch (node.Type)
			{
			case 2:
				nodeType->PutZ(row, 2);
				break;
			case 3:
				nodeType->PutZ(row, 0);
				break;
			case 4:
				nodeState->PutZ(row, true);
				break;
			}

			row++;
		}

		row = 0;
		ASTRALib::IColsPtr branchcols{ branches->Cols };
		ASTRALib::IColPtr branchHead{ branchcols->Item("ip") };
		ASTRALib::IColPtr branchTail{ branchcols->Item("iq") };
		ASTRALib::IColPtr branchr{ branchcols->Item("r") };
		ASTRALib::IColPtr branchx{ branchcols->Item("x") };
		ASTRALib::IColPtr branchb{ branchcols->Item("b") };
		ASTRALib::IColPtr branchktr{ branchcols->Item("ktr") };
		ASTRALib::IColPtr branchkti{ branchcols->Item("kti") };
		branches->PutSize(static_cast<long>(data.branches.size()));


		constexpr const char* yes = "yes";
		constexpr const char* no = "no";

		data.logger_.Log(LogMessageTypes::Info, "Transformer invert angle: {}", InvertTransformerAngle() ? yes : no);
		data.logger_.Log(LogMessageTypes::Info, "Zbase optional: {}", UseOptionalZbase() ? yes : no);

		const auto pi{ 4.0 * std::atan(1) };

		for (const auto& branch : data.branches)
		{
			branchHead->PutZ(row, branch.IdHead);
			branchTail->PutZ(row, branch.IdTail);

			struct NodeIndex
			{
				long Id;
				decltype(NodeMap)::const_iterator it;
			};

			std::array< NodeIndex, 2 > ht{ {{ branch.IdHead, NodeMap.end() } , { branch.IdTail, NodeMap.end() } } };

			for (auto&& node : ht)
				if (node.it = NodeMap.find(node.Id); node.it == NodeMap.end())
					data.logger_.Log(LogMessageTypes::Error, "Branch {} {} has wrong node {}", branch.IdHead, branch.IdTail, node.Id);

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
					Zbase *= UHnom * UHnom * std::norm(kt);		// alternative mode proposed
				else
					Zbase *= UHnom * UHnom;						// seems to be matpower default mode

				kt = UTnom / UHnom / kt;
					

				// clear ratio if it is equal to 1.0 with no angle shift
				if (std::abs(kt.real() - 1.0) < 1E-7 && kt.imag() == 0)
					kt = 0.0;

				branchktr->PutZ(row, kt.real());
				branchkti->PutZ(row, kt.imag());
				branchr->PutZ(row, branch.r * Zbase);
				branchx->PutZ(row, branch.x * Zbase);
				branchb->PutZ(row, -branch.b / Zbase);
			}

			row++;
		}

		row = 0;

		ASTRALib::IColsPtr gencols{ generators->Cols };
		ASTRALib::IColPtr genBus{ gencols->Item("Node") };
		ASTRALib::IColPtr genId{ gencols->Item("Num") };
		ASTRALib::IColPtr genPg{ gencols->Item("P") };
		ASTRALib::IColPtr genQg{ gencols->Item("Q") };
		ASTRALib::IColPtr genQmin{ gencols->Item("Qmin") };
		ASTRALib::IColPtr genQmax{ gencols->Item("Qmax") };
		generators->PutSize(static_cast<long>(data.generators.size()));

		for (const auto& gen : data.generators)
		{
			genId->PutZ(row, row + 1);
			genBus->PutZ(row, gen.Id);
			genPg->PutZN(row, gen.Pg);
			genQg->PutZN(row, gen.Qg);
			genQmin->PutZN(row, std::isinf(gen.Qmin) ? (gen.Qmin > 0 ? 1e6 : -1e6) : gen.Qmin);
			genQmax->PutZN(row, std::isinf(gen.Qmax) ? (gen.Qmax > 0 ? 1e6 : -1e6) : gen.Qmax);

			if (auto Node{ NodeMap.find(gen.Id) }; Node == NodeMap.end())
				throw CException("Generator {} assigned to wrong node {}", row + 1, gen.Id);
			else
				nodeVref->PutZN(Node->second, gen.Vg * data.buses[Node->second].Unom);

			row++;
		}

		row = 0;

		areas->PutSize(static_cast<long>(data.areas.size()));
		ASTRALib::IColsPtr areacols{ areas->Cols };
		ASTRALib::IColPtr areaId{ areacols->Item("na") };
		for (const auto& area : data.areas)
		{
			areaId->PutZ(row, area.Id);

			row++;
		}

		rastr->Save(stringutils::COM_encode(path.string()).c_str(), stringutils::COM_encode(rg2template.string()).c_str());
		data.logger_.Log(LogMessageTypes::Info, "RastrWin model is exported to {}", path.string());
	}
	catch (const _com_error& ex)
	{
		throw CException("RastrWin error: {}", stringutils::COM_decode(ex.Description()));
	}
}