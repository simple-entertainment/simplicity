cmake_minimum_required(VERSION 3.2)

include(simplicity-common.cmake)

# Project
project(simplicity)

# Paths
file(GLOB_RECURSE SRC_FILES src/main/c++/*.cpp src/main/c++/*.h)
include_directories(src/main/c++)

# Output
add_library(simplicity STATIC ${SRC_FILES})
