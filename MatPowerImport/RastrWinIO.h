#pragma once
#include "MatPowerData.h"

class RastrWinIO
{
	std::filesystem::path GetTemplatesPath() const;
	bool InvertTransformerAngle_ = false;
	bool UseOptionalZbase_ = false;
public:
	void Export(const MatPowerCase& data, const std::filesystem::path& path);
	bool InvertTransformerAngle() const { return InvertTransformerAngle_; }
	void SetInvertTransformerAngle(bool InvertTransformerAngle) { InvertTransformerAngle_ = InvertTransformerAngle; }
	bool UseOptionalZbase() const { return UseOptionalZbase_; }
	void SetUseOptionalZbase(bool UseOptionalZbase) { UseOptionalZbase_ = UseOptionalZbase; }
};
