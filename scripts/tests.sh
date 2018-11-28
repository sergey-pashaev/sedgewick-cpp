#!/usr/bin/env bash
set -Eeuo pipefail
IFS=$'\n\t'

# go to repo root
cd "${0%/*}/.."

./scripts/build.sh $@
cd build/
ctest -V .
