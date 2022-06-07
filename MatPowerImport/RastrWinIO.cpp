#include <complex>
#include <map>
#include "RastrWinIO.h"
#import "progid:Astra.Rastr.1" named_guids

void RastrWinIO::Export(const MatPowerCase& data, const std::filesystem::path& path)
{
	CoInitialize(NULL);
	ASTRALib::IRastrPtr rastr;
	if(FAILED(rastr.CreateInstance(ASTRALib::CLSID_Rastr)))
		throw CExceptionGLE("RastrWin unavailable");

	std::filesystem::path rg2template{ "d:\\documents\\RastrWin3\\shablon\\режим.rg2" };
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
		nodeBsh->PutZ(row, node.Bsh / node.Unom / node.Unom);

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

	const auto pi{ 4.0 * std::atan(1) };
	
	for (const auto& branch : data.branches)
	{
		std::complex<double> kt{ std::polar(branch.ktr, branch.kti / 180.0 * pi) };
		branchHead->PutZ(row, branch.IdHead);
		branchTail->PutZ(row, branch.IdTail);



		if (auto NodeHead{ NodeMap.find(branch.IdHead) }; NodeHead == NodeMap.end())
			throw CException("Branch {} {} has wrong node {}", branch.IdHead, branch.IdTail, branch.IdHead);
		else
		{
			const auto U1nom{ data.buses[NodeHead->second].Unom };
			auto Zbase{ U1nom };
			Zbase *= Zbase / data.BaseMVA_;
			//Zbase = 1.0;
			branchr->PutZ(row, branch.r * Zbase);
			branchx->PutZ(row, branch.x * Zbase);
			branchb->PutZ(row, branch.b / Zbase);

			if (auto NodeTail{ NodeMap.find(branch.IdTail) }; NodeTail == NodeMap.end())
				throw CException("Branch {} {} has wrong node {}", branch.IdHead, branch.IdTail, branch.IdTail);
			else
			{
				const auto U2nom{ data.buses[NodeTail->second].Unom };

				if (std::abs(kt) < 1E-7)
					kt = 1.0;

				branchktr->PutZ(row, U2nom / U1nom / kt.real());
				branchkti->PutZ(row, kt.imag());
			}
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

	for (const auto& gen: data.generators)
	{
		genId->PutZ(row, row + 1);
		genBus->PutZ(row, gen.Id);
		genPg->PutZN(row, gen.Pg);
		genQg->PutZN(row, gen.Qg);
		genQmin->PutZN(row, gen.Qmin);
		genQmax->PutZN(row, gen.Qmax);

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
}