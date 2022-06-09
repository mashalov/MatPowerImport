# MatPowerImport

This utility is designed to convert [matpower](https://github.com/MATPOWER/matpower) caseformat to rg2 format. The latter is the file format of [RastrWin](https://rastwin.ru), an industrial power system analysis software, best known in Russia.

## Build

Since the matpower caseformat is actually a Matlab m-file, MatPowerImport relies on [Antlr](https://github.com/antlr/antlr4) parsing. You must compile the C++ runtime antlr4-runtime.lib for debug and release builds.

## Usage

Run MatPowerImport from the console with at least one argument - the path to the matpower caseformat. The second argument is optional. This is the path to the exported rg2 file. If there is only one caseformat path, the resulting rg2 file will be written to the same folder with the name caseformat matpower and extension "rg2".
