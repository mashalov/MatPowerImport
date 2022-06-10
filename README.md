# MatPowerImport

This utility is designed to convert [MATPOWER](https://github.com/MATPOWER/matpower) caseformat to rg2 format. The latter is the file format of [RastrWin](https://rastrwin.ru), an industrial power system analysis software, best known in Russia.

## Build

Since the MATPOWER caseformat is actually a Matlab m-file, MatPowerImport relies on [Antlr](https://github.com/antlr/antlr4) parsing. You must compile the C++ runtime antlr4-runtime.lib for debug and release builds. Also RastrWin must be installed in order to access its type library via progID.

## Usage

Run MatPowerImport from the console with at least one argument - the path to the MATPOWER caseformat. The second argument is optional. This is the path to the exported rg2 file. If there is only one caseformat path, the resulting rg2 file will be written to the same folder with the name of the MATPOWER caseformat file and extension "rg2".
