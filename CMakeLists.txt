# Requirement
cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_STANDARD 99)

# Project configuration
project(minigimp C)
file(GLOB_RECURSE source_files src/*)
include_directories(src)

# Executable file
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${source_files})
