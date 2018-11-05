#!/usr/bin/env bash

# if any command inside script returns error, exit and return that error
set -e

# magic line to ensure that we're always inside the root of our repo,
# no matter from which directory we'll run script
# thanks to it we can just enter `./scripts/run-tests.sh`
cd "${0%/*}/.."

make && make -C build/ -j4 test
