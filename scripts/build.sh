#!/usr/bin/env bash
set -Eeuo pipefail
IFS=$'\n\t'

# magic line to ensure that we're always inside the root of our repo,
# no matter from which directory we'll run script
# thanks to it we can just enter `./scripts/run-tests.sh`
cd "${0%/*}/.."

mkdir -p build/ && cd build/
CC=clang CXX=clang++ cmake $@ ..
make -j4
cd ../
