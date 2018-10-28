#!/bin/bash

cd build/
# CC=clang CXX=clang++ cmake .. # clang
make -j4 test ARGS="-V"
cd ../
