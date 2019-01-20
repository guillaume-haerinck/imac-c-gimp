# Requirement
cmake_minimum_required(VERSION 3.1)
set(CMAKE_C_STANDARD 99)

# Project configuration
project(minigimp C)
file(GLOB_RECURSE source_files src/*)
include_directories(src)

# Executable file
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
add_executable(${PROJECT_NAME} ${source_files})
target_link_libraries(${PROJECT_NAME} m) # Add math.h

# Warnings
if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wconversion -Wsign-conversion -pedantic)
else (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
endif()