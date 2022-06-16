#pragma once
#include "MatPowerData.h"
#import "progid:Astra.Rastr.1" named_guids


class RastrWinIO
{
	class RastrWinDB
	{
	public:

		ASTRALib::IRastrPtr rastr;

		ASTRALib::ITablePtr nodes;
		ASTRALib::ITablePtr branches;
		ASTRALib::ITablePtr generators;
		ASTRALib::ITablePtr areas;
		ASTRALib::ITablePtr param;

		ASTRALib::IColPtr nodeId;
		ASTRALib::IColPtr nodeUnom;
		ASTRALib::IColPtr nodePn;
		ASTRALib::IColPtr nodeQn;
		ASTRALib::IColPtr nodeType;
		ASTRALib::IColPtr nodeState;
		ASTRALib::IColPtr nodeV;
		ASTRALib::IColPtr nodeDelta;
		ASTRALib::IColPtr nodeArea;
		ASTRALib::IColPtr nodeGsh;
		ASTRALib::IColPtr nodeBsh;
		ASTRALib::IColPtr nodeVref;
		ASTRALib::IColPtr nodeName;

		ASTRALib::IColPtr branchHead;
		ASTRALib::IColPtr branchTail;
		ASTRALib::IColPtr branchr;
		ASTRALib::IColPtr branchx;
		ASTRALib::IColPtr branchb;
		ASTRALib::IColPtr branchktr;
		ASTRALib::IColPtr branchkti;

		ASTRALib::IColPtr genBus;
		ASTRALib::IColPtr genId;
		ASTRALib::IColPtr genPg;
		ASTRALib::IColPtr genQg;
		ASTRALib::IColPtr genQmin;
		ASTRALib::IColPtr genQmax;

		ASTRALib::IColPtr areaId;

		ASTRALib::IColPtr flat;
		ASTRALib::IColPtr itmax;


		std::filesystem::path rg2template;

		void Init();
		RastrWinDB();

		static std::filesystem::path GetTemplatesPath();
	};

	bool InvertTransformerAngle_ = false;
	bool UseOptionalZbase_ = false;
	bool LoadFlow_ = false;
	bool LoadFlowFlat_ = false;
	bool LoadFlowStats_ = false;
	bool StatsOnly_ = false;

	const double pi = 4.0 * std::atan(1);

	struct LFStats
	{
		double Vstd = 0.0;	// voltage magnitude standard deviation
		double Astd = 0.0;	// voltage angle standard deviation
	};

	RastrWinDB db;

public:
	void Import(MatPowerCase& data, const std::filesystem::path& path);
	void Export(const MatPowerCase& data, const std::filesystem::path& path);
	bool InvertTransformerAngle() const { return InvertTransformerAngle_; }
	void SetInvertTransformerAngle(bool InvertTransformerAngle) { InvertTransformerAngle_ = InvertTransformerAngle; }
	bool UseOptionalZbase() const { return UseOptionalZbase_; }
	void SetUseOptionalZbase(bool UseOptionalZbase) { UseOptionalZbase_ = UseOptionalZbase; }
	bool LoadFlow() const { return LoadFlow_; }
	void SetLoadFlow(bool LoadFlow) { LoadFlow_ = LoadFlow; }
	bool LoadFlowFlat() const { return LoadFlowFlat_; }
	LFStats Stats(const MatPowerCase& data) const;
	void SetLoadFlowFlat(bool LoadFlowFlat)
	{
		LoadFlowFlat_ = LoadFlowFlat;
		if (LoadFlowFlat)
			SetLoadFlow(LoadFlowFlat);
	}
	bool LoadFlowStats() const { return LoadFlowStats_; }
	void SetLoadFlowStats(bool LoadFlowStats)
	{
		LoadFlowStats_ = LoadFlowStats;
		if (LoadFlowStats)
			SetLoadFlow(LoadFlowStats);
	}
	bool StatsOnly() const { return StatsOnly_; }
	void SetStatsOly(bool StatsOnly)
	{
		SetLoadFlowStats(true);
		StatsOnly_ = StatsOnly;
	}

	static constexpr const char* cszRastrWinUnavailable = "RastrWin Unavailable";
};


