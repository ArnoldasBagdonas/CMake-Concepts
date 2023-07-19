# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name and language standard
project(exampleproject)
set(CMAKE_CXX_STANDARD 11)

# Include the clang-format configuration file
include(include/clang-format.cmake)

# Add subdirectories for each subproject
add_subdirectory(subproject1)
add_subdirectory(subproject2)
