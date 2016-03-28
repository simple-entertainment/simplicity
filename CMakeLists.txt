cmake_minimum_required(VERSION 3.2)

include(simplicity-common.cmake)

# Project
#########################
project(simplicity)

# Source
#########################
file(GLOB_RECURSE SRC_FILES src/main/c++/*.cpp src/main/c++/*.h)

# Target
#########################
add_library(simplicity ${SIMPLE_LINK_TYPE} ${SRC_FILES} src/main/c++/simplicity/scripting/ScriptingEngineState.cpp src/main/c++/simplicity/scripting/ScriptingEngineState.h)
target_include_directories(simplicity PUBLIC src/main/c++)
