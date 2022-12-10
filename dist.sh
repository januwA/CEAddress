#!/bin/bash

# debug
# cmake -S . -B build
# cmake --build build


cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLE=ON -S . -B build
cmake --build build --config Release
cmake --install build --config Release