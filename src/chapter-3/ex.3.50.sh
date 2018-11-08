#!/usr/bin/env bash

source ../utils.sh

Ns=(1000 10000 100000 1000000)
Ms=(2)

for i in "${Ns[@]}"; do
    for j in "${Ms[@]}"; do
	NEW=$({ time ./ex.3.49 "$i" "$j" >/dev/null; }  2>&1 | grep real | cut -f 2)
	FREELIST=$({ time ./program.3.13 "$i" "$j" >/dev/null; }  2>&1 | grep real | cut -f 2)
	echo "freelist=$FREELIST new=$NEW N=$i M=$j"
    done
done
