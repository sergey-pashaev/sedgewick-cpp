#!/usr/bin/env bash

function mem_usage() {
    local bin=$1
    local pid=$(valgrind --tool=massif --time-unit=B --stacks=yes ${bin} 2>&1 | tail -n 1)
    pid=${pid//=/} # replace =
    pid=${pid::-1} # cut last symbol
    echo "memory usage of ${bin} (massif.out.${pid}):"
    ms_print "massif.out.${pid}"
    echo
}

function cpu_usage() {
    local bin=$1
    echo "cpu usage of ${bin}:"
    valgrind --tool=callgrind ${bin} 2>&1
    echo
}
