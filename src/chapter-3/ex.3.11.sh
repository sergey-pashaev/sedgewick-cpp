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

source ../utils.sh

mem_usage ./ex.3.11.char
mem_usage ./ex.3.11.bit

cpu_usage ./ex.3.11.char
cpu_usage ./ex.3.11.bit
