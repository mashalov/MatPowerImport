#pragma once
#include "MatPowerData.h"

class RastrWinIO
{
	std::filesystem::path GetTemplatesPath() const;
public:
	void Export(const MatPowerCase& data, const std::filesystem::path& path);
};
