#!/bin/bash

path_to_src=$1

# Clean any existing build files
rm -rf scan-build

# Create a new build directory
mkdir scan-build
cd scan-build

# Generate the build system with scan-build enabled
scan-build -o . cmake -DCMAKE_BUILD_TYPE=Debug $path_to_src

# Build the subproject using scan-build
scan-build -o . make
