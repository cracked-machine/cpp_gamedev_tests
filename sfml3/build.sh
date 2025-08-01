#!/bin/bash

cd sfml3
cmake -S . -B build -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=cmake-toolchain-mingw64-x86_64.cmake \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cmake --build build --parallel

cp /usr/lib/gcc/x86_64-w64-mingw32/14-win32/libstdc++-6.dll build/bin/libstdc++-6.dll
cp /usr/lib/gcc/x86_64-w64-mingw32/14-win32/libgcc_s_seh-1.dll build/bin/libgcc_s_seh-1.dll
