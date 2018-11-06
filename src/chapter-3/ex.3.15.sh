#!/usr/bin/env bash

source ../utils.sh

Ns=(1000 10000 100000 1000000)

for N in "${Ns[@]}"; do
    check=$(valgrind_Ir ./ex.3.15.check "$N")
    no_check=$(valgrind_Ir ./ex.3.15.no-check "$N")
    change=$(percentage_change "${check}" "${no_check}")
    echo "w/ check (${check}) vs w/o check (${no_check}) for N=${N} is ${change}% change"
done
