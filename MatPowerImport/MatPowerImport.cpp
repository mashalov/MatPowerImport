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
        logger.Log(LogMessageTypes::Info, "Usage: (matpower m-file path) [rastrwin rg2-file path]");
        return 1;
    }
        

    if (argc == 2)
        importpath = argv[1];

    if(argc == 3)
        rastrwinexportpath = argv[2];

    if (rastrwinexportpath.empty())
    {
        rastrwinexportpath = importpath;
        rastrwinexportpath.replace_extension(".rg2");
    }
    
    try
    {
        MatPowerCase Case(logger);
        Case.Import(importpath);
        RastrWinIO rastr;
        rastr.Export(Case, rastrwinexportpath);
    }
    catch (const std::exception& ex)
    {
        logger.Log(LogMessageTypes::Error, ex.what());
    }
}
