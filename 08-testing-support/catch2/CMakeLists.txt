# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.14)

# Set the project name
project(exampleproject)

# Set the C++ standard to 14
set(CMAKE_CXX_STANDARD 14)

# Disable C++ extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# Enforce the C++ standard to be required
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the FetchContent module for downloading external dependencies
include(FetchContent)

# Declare Catch2 as an external dependency to be fetched
FetchContent_Declare(
  Catch2
  GIT_SHALLOW    TRUE
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.2.0
)

# Fetch and make Catch2 available for the project
FetchContent_MakeAvailable(Catch2)

# Add the Catch2 module path to the CMake module search path
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)

#############################################
# Unit tests
#############################################

# Enable testing in CMake
enable_testing()

# Add the test binary target, specifying the source file for the test
add_executable(
  test_binary
  ${PROJECT_SOURCE_DIR}/tests/test_bdd_example.cpp
)

# Link the test binary with Catch2 library
target_link_libraries(
  test_binary
  PRIVATE Catch2::Catch2WithMain
)

# Include CTest for test discovery and execution
include(CTest)

# Include Catch for test macros and utilities
include(Catch)

# Discover and execute tests using Catch
catch_discover_tests(test_binary)
# or
#add_test(test_all test_binary)
