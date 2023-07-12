# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Require the specified C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Disable compiler-specific extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# Add compiler options for coroutines
add_compile_options("-fcoroutines")

# Regular expression to extract the version from the source code
set(VERSION_REGEX "#define COGEN_VERSION[ \t]+\"(.+)\"")

# Read the version string from the source file using the regex
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/include/cogen.hpp"
    VERSION_STRING REGEX ${VERSION_REGEX})

# Extract the version from the captured regex group
string(REGEX REPLACE ${VERSION_REGEX} "\\1" VERSION_STRING "${VERSION_STRING}")

# Define the project with the specified name, language, and version
project(exampleproject LANGUAGES CXX VERSION ${VERSION_STRING})

# Check if the minor version is less than 2
if(PROJECT_VERSION_MINOR LESS 2)
    # Print an error message and terminate the configuration if the version is not supported
    message(FATAL_ERROR "COGEN_VERSION: " ${VERSION_STRING} " is not supported!!!")
else()
    # Print the version string if it is supported
    message(STATUS "COGEN_VERSION: " ${VERSION_STRING})
endif()

# Include the directory with the header files
include_directories(include)

# Create an executable target with the specified name and source file
add_executable(${PROJECT_NAME} main.cpp)

# Add the include directory to the target's include directories
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
