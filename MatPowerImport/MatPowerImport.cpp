// MatPowerImport.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "MatPowerData.h"
#include "RastrWinIO.h"

int main(int argc, char* argv[])
{
    CPlainRastrEventSource eventSource;
    CPlainLogger logger(&eventSource);

    std::filesystem::path importpath;
    std::filesystem::path rastrwinexportpath;

    if (argc == 1)
    {
        logger.Log(LogMessageTypes::Info, "Usage: [options] (matpower m-file path) [rastrwin rg2-file path]");
        logger.Log(LogMessageTypes::Info, "\t-angle - invert transformer angle");
        logger.Log(LogMessageTypes::Info, "\t-zbopt - optional Zbase calculation: Zbase = Vf^2*|ratio/_angle|^2/baseMVA (default is Zbase = Vf^2/baseMVA)");
        return 1;
    }

    RastrWinIO rastr;

    int pathes{ 0 };
    for (int cmdindex = 1; cmdindex < argc; cmdindex++)
    {
        std::string opt{ argv[cmdindex] };
        stringutils::tolower(opt);
        stringutils::trim(opt);
        if(opt == "-angle")
            rastr.SetInvertTransformerAngle(true);
        else if(opt == "-zbopt")
            rastr.SetUseOptionalZbase(true);
        
        if (opt.length() > 0 && opt[0] != '-')
        {
            switch (pathes)
            {
            case 0:
                importpath = argv[cmdindex];
                break;
            case 1:
                rastrwinexportpath = argv[cmdindex];
                break;
            }
            pathes++;
        }
    }

    constexpr const char* rg2 = ".rg2";
        
    if (rastrwinexportpath.empty())
    {
        rastrwinexportpath = importpath;
        rastrwinexportpath.replace_extension(rg2);
    }
    else if (!rastrwinexportpath.has_extension() && importpath.has_filename())
    {
        rastrwinexportpath /= importpath.filename();
        rastrwinexportpath.replace_extension(rg2);
    }
     
    
    try
    {
        MatPowerCase Case(logger);
        Case.Import(importpath);
        rastr.Export(Case, rastrwinexportpath);
    }
    catch (const std::exception& ex)
    {
        logger.Log(LogMessageTypes::Error, ex.what());
    }
}
