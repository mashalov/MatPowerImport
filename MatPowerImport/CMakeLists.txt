# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.18)
project ("MatPower")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include(FetchContent)

FetchContent_Declare(antlr4
  GIT_REPOSITORY https://github.com/antlr/antlr4.git
)
FetchContent_Populate(antlr4)

FetchContent_GetProperties(antlr4
  SOURCE_DIR antlrSrc
  BINARY_DIR antlrBin
)
# access umbrella antlr4 includes
set(ANTLR_INCLUDES "${antlrSrc}/runtime/Cpp/runtime/src")

FetchContent_Declare(fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
)
FetchContent_Populate(fmtlib)

FetchContent_GetProperties(fmtlib
  SOURCE_DIR fmtSrc
  BINARY_DIR fmtBin
)

# access fmt includes
set(FMT_INCLUDES "${fmtSrc}/include")

set(ANTLR_BUILD_CPP_TESTS OFF)
set(ANTLR4CPP_STATIC ON)
set(WITH_STATIC_CRT OFF)

add_compile_definitions(NOMINMAX ANTLR4CPP_STATIC WIN32_LEAN_AND_MEAN)

# build dependencies

add_subdirectory(${fmtSrc})
add_subdirectory(${antlrSrc}/runtime/Cpp)

# build antlr4 parser from .g4 

set(ANTLR_COMPILER ${CMAKE_CURRENT_SOURCE_DIR}/antlr/antlr-4.13.0-complete.jar)
set(ANTLR_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Generated/)
set(ANTLR_OUTPUT 
    "${ANTLR_OUTPUT_DIR}/MpcParser.cpp"
    "${ANTLR_OUTPUT_DIR}/MpcBaseVisitor.cpp"
    "${ANTLR_OUTPUT_DIR}/MpcLexer.cpp"
    "${ANTLR_OUTPUT_DIR}/MpcVisitor.cpp"
)

add_custom_command(
      OUTPUT ${ANTLR_OUTPUT}
      COMMAND "java"
      ARGS -jar ${ANTLR_COMPILER}
        -Dlanguage=Cpp
        -no-listener
        -visitor
        -o ${ANTLR_OUTPUT_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Mpc.g4
      COMMENT "Generating antlr4 parser"
      VERBATIM
)

# link parser as library 

add_library(MpcParser ${ANTLR_OUTPUT})
target_compile_definitions(MpcParser PRIVATE "ANTLR4CPP_STATIC")
target_include_directories(MpcParser PRIVATE ${ANTLR_INCLUDES})

# build executable 

set(SOURCES
	PlainLogger.cpp
	MatPowerData.cpp
	RastrWinIO.cpp
	MatPowerImport.cpp
)

add_executable(MatPowerImport ${SOURCES})

target_compile_definitions(MatPowerImport
    PRIVATE 
        "ANTLR4CPP_STATIC" 
        "_CONSOLE" 
        "NOGDI" 
        "NOMINMAX" 
        "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING" 
        "_MBCS"
)

target_include_directories(MatPowerImport PRIVATE ${FMT_INCLUDES} ${ANTLR_INCLUDES})
target_link_libraries(MatPowerImport fmt::fmt antlr4_static MpcParser) 