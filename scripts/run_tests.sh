#!/bin/bash

# Create build directory at the project root
mkdir -p ../build
cd ../build

# Run CMake from the build directory
cmake ..

# Build the project using Makefiles
make

# Run the tests
make run_tests