# MatPowerImport
This utility is designed to convert [MATPOWER](https://github.com/MATPOWER/matpower) caseformat to rg2 format. The latter is the file format of [RastrWin](https://rastrwin.ru), an industrial power system analysis software, best known in Russia.
## Build
Since the MATPOWER caseformat is actually a Matlab m-file, MatPowerImport relies on [Antlr](https://github.com/antlr/antlr4) parsing. You must compile the C++ runtime antlr4-runtime-static.lib for debug and release builds. RastrWin must also be installed to access its type library via progID. You can use CMake with included CMakeLists.txt. Locate this file in the MatPowerImport folder, create subfolder 'build' and jump into it. Run:
	`cmake ../.`
and then
	`cmake --build .`
Build configuration can be selected
	`cmake --build . --config Release`
or 
	`cmake --build . --config Debug`
Known Issues: sometimes the compiler may show an error in the min/max function that conflicts with the Windows header defined counterparts. A known affected source is SerializedATNView.h from the Antlr4 package. The easiest way to fix this is to simply replace `std::min` with `(std::min)` and `std::max` with `(std::max)`. CMake build downloads latest Antlr runtime and [fmt](https://github.com/fmtlib/fmt) releases, but Antlr compiler used is 4.13.0. Visual Studio project locked to Antlr 4.13.0 release. You can upgrade your project (both compiler or runtime), but it should be synced with Antlr C++ runtime.
## Usage
Run MatPowerImport from the console with at least one argument - the path to the MATPOWER caseformat. The second argument is optional. This is the path to rg2 file to be exported . If there is only one caseformat path, the resulting rg2 file will be written to the same folder with the name of the MATPOWER caseformat file and extension "rg2". 
There are some options to run MatPowerImport. Place options before pathames as follows:   
`[options] (matpower m-file path) [RastrWin rg2-file path]`   
-angle - invert transformer angle.   
-zbopt - optional Zbase calculation: Zbase = Vf^2/baseMVA (default is Zbase = Vf^2*|ratio/angle|^2/baseMVA).   
-lf    - solve load flow with RastrWin before export. Default is to leave caseformat solution intact.   
-flat  - solve load flow with RastrWin before export using flat start. Default is casepower solution.   
-stats - solve load flow with RastrWin before export and print difference statistics  (standard deviations of voltage magnitudes and angles between caseformat and RastrWin solutions).   
-export  - special option to reverse MatPowerImport operation - read rg2 file and output it to caseformat. The paths in the command line are reverted as well : `-export (RastrWin rg2-file path) [matpower m-file path]`. Of course, some limitiations of model conversion apply.   
