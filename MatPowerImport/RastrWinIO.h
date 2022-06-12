#pragma once
#include "MatPowerData.h"
#import "progid:Astra.Rastr.1" named_guids

class RastrWinIO
{
	std::filesystem::path GetTemplatesPath() const;
	bool InvertTransformerAngle_ = false;
	bool UseOptionalZbase_ = false;
	bool LoadFlow_ = false;
	bool LoadFlowFlat_ = false;
	bool LoadFlowStats_= false;

	ASTRALib::IRastrPtr rastr;

	const double pi = 4.0 * std::atan(1);

	struct LFStats
	{
		double Vstd = 0.0;	// voltage magnitude standard deviation
		double Astd = 0.0;	// voltage angle standard deviation
	};

public:
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
		if(LoadFlowStats)
			SetLoadFlow(LoadFlowStats);
	}
};
