#!/bin/bash

cd sdl3
cmake -S . -B build -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=cmake-toolchain-mingw64-x86_64.cmake
cmake --build build --parallel