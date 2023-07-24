# This script automates the process of building, testing, and submitting test results to CDash
# as part of the Continuous Integration (CI) pipeline. It supports various build configurations,
# code coverage reporting, and memory sanitizers (AddressSanitizer, LeakSanitizer, ThreadSanitizer,
# MemorySanitizer, UndefinedBehaviorSanitizer, and Valgrind).

cmake_minimum_required(VERSION 3.14)

# Code Coverage
# Enable or Disable code coverage reporting.
option(ENABLE_COVERAGE OFF)

# Build Configuration
# Define the build name (e.g., "Debug", "Release", "MinSizeRel", "RelWithDebInfo",
# "Coverage", "AddressSanitizer", "LeakSanitizer", "ThreadSanitizer", "MemorySanitizer",
# "UndefinedBehaviorSanitizer" or "Valgrind").
option(BUILD_NAME Debug)

# Test configuration
# Include the CTestConfig.cmake file to customize testing configurations and variables.
include(${CTEST_SCRIPT_DIRECTORY}/CTestConfig.cmake)

# General settings
# Specify the testing site (CDash dashboard) where the test results will be reported.
site_name(CTEST_SITE)

# CTest Model
# Choose the testing model: Continuous, Nightly, or Experimental.
set(CTEST_MODEL "Experimental")

# CMake Generator
# Set the CMake generator to use (e.g., "Unix Makefiles" or "Ninja").
set(CTEST_CMAKE_GENERATOR "Unix Makefiles")

# Source and Binary Directories
# Set the source and binary directories for the CTest testing process.
set(CTEST_SOURCE_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}")
set(CTEST_BINARY_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}/build")

# Build Configuration
set(CTEST_BUILD_NAME "CI-${BUILD_NAME}")
set(configureOpts -DBUILD_NAME:STRING=${BUILD_NAME})

# CTest Configuration Type
# Set the CTest configuration type based on the selected BUILD_NAME.
set(CTEST_CONFIGURATION_TYPE Debug)
if (BUILD_NAME MATCHES "Debug|Release|MinSizeRel|RelWithDebInfo")
  set(CTEST_CONFIGURATION_TYPE ${BUILD_NAME})
endif()

# Code Coverage
# Enable code coverage reporting if the BUILD_NAME is set to "Coverage."
option(ENABLE_COVERAGE OFF)
if (BUILD_NAME MATCHES "Coverage")
  set(ENABLE_COVERAGE ON)
endif()

# Memory Sanitizers
# Set the CTest memory check type to the selected BUILD_NAME if it corresponds to a memory sanitizer.
if (BUILD_NAME MATCHES "AddressSanitizer|LeakSanitizer|ThreadSanitizer|MemorySanitizer|UndefinedBehaviorSanitizer|Valgrind")
  set(CTEST_MEMORYCHECK_TYPE ${BUILD_NAME})
endif()

# Additional Options for Coverage
if (ENABLE_COVERAGE)
  list(APPEND configureOpts -DENABLE_COVERAGE=${ENABLE_COVERAGE})
  set(CTEST_COVERAGE_COMMAND "gcov")
  set(CTEST_CUSTOM_COVERAGE_EXCLUDE
    "${CTEST_BINARY_DIRECTORY}/_deps/googletest-src/*"
  )
endif()

# Empty the Binary Directory
# Clear the contents of the binary directory to ensure a clean build.
ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})

# Start Testing
# Initialize the testing process, specifying the testing model as "Experimental."
ctest_start(Experimental)

# CTest Configure
# Configure the build process with the provided configureOpts (additional options passed to CMake).
ctest_configure(OPTIONS "${configureOpts}")

# CTest Build
# Initiate the build process using CMake.
ctest_build()

# CTest Test or Memcheck
# Depending on whether memory sanitizers are used, run tests using CTest or execute memory sanitizers.
if (NOT DEFINED CTEST_MEMORYCHECK_TYPE OR "${CTEST_MEMORYCHECK_TYPE}" STREQUAL "")
  ctest_test()
else()
  ctest_memcheck()
endif()

# CTest Coverage
# Generate code coverage reports if code coverage is enabled.
if (ENABLE_COVERAGE)
  ctest_coverage()
endif()

# CTest Submit
# Submit the test results to the CDash server for reporting and analysis.
ctest_submit()
