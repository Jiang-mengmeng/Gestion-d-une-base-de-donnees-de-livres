#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Go into build directory
pushd build

# Run cmake and make
cmake ..
make

# Go back to the root directory
popd
