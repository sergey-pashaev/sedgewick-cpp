#!/usr/bin/env bash

#  ex.3.11.char

#  en: Modify our implementation of the sieve of Eratosthenes (Program
#  3.5) to use an array of (i) chars; and (ii) bits. Determine the
#  effects of these changes on the amount of space and time used by
#  the program.

#  ru: Измените реализацию решета Эратосфена (program.3.5) для
#  использования массива (1) символов и (2) разрядов. Определите
#  влияние этих изменений на расход памяти и времени, используемых
#  программой.

function mem_usage() {
    local bin=$1
    local pid=$(valgrind --tool=massif --time-unit=B --stacks=yes ${bin} 2>&1 | tail -n 1)
    pid=${pid//=/} # replace =
    pid=${pid::-1} # cut last symbol
    echo "memory usage of ${bin} (massif.out.${pid}):"
    ms_print "massif.out.${pid}" | tail -n 7
    echo
}

function cpu_usage() {
    local bin=$1
    echo "cpu usage of ${bin}:"
    valgrind --tool=callgrind ${bin} 2>&1  | tail -n 4
    echo
}

mem_usage ./ex.3.11.char
mem_usage ./ex.3.11.bit

cpu_usage ./ex.3.11.char
cpu_usage ./ex.3.11.bit
