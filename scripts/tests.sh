#!/usr/bin/env bash

set -eu

# go to repo root
cd "${0%/*}/.."

./scripts/build.sh
cd build/
ctest -V .
