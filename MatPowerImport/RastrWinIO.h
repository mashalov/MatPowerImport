#pragma once
#include "MatPowerData.h"

class RastrWinIO
{
public:
	void Export(const MatPowerCase& data, const std::filesystem::path& path);
};
