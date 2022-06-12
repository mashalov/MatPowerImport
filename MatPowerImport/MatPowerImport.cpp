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
        logger.Log(LogMessageTypes::Info, "Usage: [options] (matpower m-file path) [RastrWin rg2-file path]");
        logger.Log(LogMessageTypes::Info, "\t-angle - invert transformer angle");
        logger.Log(LogMessageTypes::Info, "\t-zbopt - optional Zbase calculation: Zbase = Vf^2/baseMVA (default is Zbase = Vf^2*|ratio/_angle|^2/baseMVA)");
        logger.Log(LogMessageTypes::Info, "\t-lf    - solve load flow with RastrWin before export");
        logger.Log(LogMessageTypes::Info, "\t-flat  - solve load flow with RastrWin before export using flat start");
        logger.Log(LogMessageTypes::Info, "\t-stats - solve load flow with RastrWin before export and print difference statistics" \
                                          "(standard deviations of voltage magnitudes and angles between caseformat and RastrWin solutions");
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
        else if (opt == "-lf")
            rastr.SetLoadFlow(true);
        else if (opt == "-flat")
            rastr.SetLoadFlowFlat(true);
        else if (opt == "-stats")
            rastr.SetLoadFlowStats(true);
                
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
