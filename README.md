# MatPowerImport
This utility is designed to convert [MATPOWER](https://github.com/MATPOWER/matpower) caseformat to rg2 format. The latter is the file format of [RastrWin](https://rastrwin.ru), an industrial power system analysis software, best known in Russia.
## Build
Since the MATPOWER caseformat is actually a Matlab m-file, MatPowerImport relies on [Antlr](https://github.com/antlr/antlr4) parsing. You must compile the C++ runtime antlr4-runtime.lib for debug and release builds. RastrWin must also be installed to access its type library via progID. You can use CMake with included CMakeLists.txt. Locate this file in the MatPowerImport folder, create subfolder 'build' and jump into it. Run:
`cmake ../.`
and then
`cmake --build .`
Known Issues: sometimes the compiler may show an error in the min/max function that conflicts with the Windows header defined counterparts. A known affected source is SerializedATNView.h from the Antlr4 package. The easiest way to fix this is to simply replace std::min with (std::min) and std::max with (std::max).
## Usage
Run MatPowerImport from the console with at least one argument - the path to the MATPOWER caseformat. The second argument is optional. This is the path to the exported rg2 file. If there is only one caseformat path, the resulting rg2 file will be written to the same folder with the name of the MATPOWER caseformat file and extension "rg2". 
There are some options to run MatPowerImport. Place options before pathames as follows:
`[options] (matpower m-file path) [rastrwin rg2-file path]`
-angle - invert transformer angle
-zbopt - optional Zbase calculation: Zbase = Vf^2^/baseMVA (default is Zbase = Vf^2^*|ratio/_angle|^2^/baseMVA)
-lf    - solve load flow with rastr before export
-flat  - solve load flow with rastr before export using flat start
-stats - solve load flow with rastr before export and print difference statistics
