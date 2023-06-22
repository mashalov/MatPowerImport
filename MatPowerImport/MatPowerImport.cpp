// MatPowerImport.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "MatPowerData.h"
#include "RastrWinIO.h"
#include "PackageVersion.h"
#include "FmtFormatters.h"

int main(int argc, char* argv[])
{
    CPlainRastrEventSource eventSource;
    CPlainLogger logger(&eventSource);

    std::filesystem::path matpowerpath;
    std::filesystem::path rastrwinpath;

    logger.Log(LogMessageTypes::Info, "MatpowerImport v{}, © Eugene Mashalov, 2023. " 
                                      "https://github.com/mashalov/MatPowerImport", 
                                       PackageVersion);

    if (argc == 1)
    {
        logger.Log(LogMessageTypes::Info, "Usage: [options] (matpower m-file path) [RastrWin rg2-file path]");
        logger.Log(LogMessageTypes::Info, "\t-angle - invert transformer angle");
        logger.Log(LogMessageTypes::Info, "\t-zbopt - optional Zbase calculation: Zbase = Vf^2/baseMVA (default is Zbase = Vf^2*|ratio/_angle|^2/baseMVA)");
        logger.Log(LogMessageTypes::Info, "\t-lf    - solve load flow with RastrWin before export");
        logger.Log(LogMessageTypes::Info, "\t-flat  - solve load flow with RastrWin before export using flat start");
        logger.Log(LogMessageTypes::Info, "\t-stats - solve load flow with RastrWin before export and print difference statistics " \
                                          "(standard deviations of voltage magnitudes and angles between caseformat and RastrWin solution)");
        return 1;
    }

    RastrWinIO rastr;

    bool Import = true;

    int pathes{ 0 };
    for (int cmdindex = 1; cmdindex < argc; cmdindex++)
    {
        std::string opt{ argv[cmdindex] };
        stringutils::tolower(opt);
        stringutils::trim(opt);
        if (opt == "-angle")
            rastr.SetInvertTransformerAngle(true);
        else if (opt == "-zbopt")
            rastr.SetUseOptionalZbase(true);
        else if (opt == "-lf")
            rastr.SetLoadFlow(true);
        else if (opt == "-flat")
            rastr.SetLoadFlowFlat(true);
        else if (opt == "-stats")
            rastr.SetLoadFlowStats(true);
        else if (opt == "-statsonly")
            rastr.SetStatsOly(true);
        else if (opt == "-export")
            Import = false;
                
        if (opt.length() > 0 && opt[0] != '-')
        {
            switch (pathes)
            {
            case 0:
                matpowerpath = argv[cmdindex];
                break;
            case 1:
                rastrwinpath = argv[cmdindex];
                break;
            }
            pathes++;
        }
    }



    constexpr const char* rg2 = ".rg2";
    constexpr const char* mext = ".m";
     
    
    try
    {
        MatPowerCase Case(logger);
        if (Import)
        {
            if (rastrwinpath.empty())
            {
                rastrwinpath = matpowerpath;
                rastrwinpath.replace_extension(rg2);
            }
            else if (!rastrwinpath.has_extension() && matpowerpath.has_filename())
            {
                rastrwinpath /= matpowerpath.filename();
                rastrwinpath.replace_extension(rg2);
            }

            Case.SetSilent(rastr.StatsOnly());
            Case.Import(matpowerpath);
            rastr.Export(Case, rastrwinpath);
        }
        else
        {
            std::swap(matpowerpath, rastrwinpath);

            if (matpowerpath.empty())
            {
                matpowerpath = rastrwinpath;
                matpowerpath.replace_extension(mext);
            }
            else if (!matpowerpath.has_extension() && rastrwinpath.has_filename())
            {
                matpowerpath /= rastrwinpath.filename();
                matpowerpath.replace_extension(mext);
            }

            Case.SetSilent(rastr.StatsOnly());
            rastr.Import(Case, rastrwinpath);
            Case.Export(matpowerpath);
        }
    }
    catch (const std::exception& ex)
    {
        logger.Log(LogMessageTypes::Error, ex.what());
    }
}
