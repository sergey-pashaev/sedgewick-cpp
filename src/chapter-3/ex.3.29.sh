#!/usr/bin/env bash

Ns=(1000 10000 100000 1000000)
Ms=(2 3 5 10)

for i in "${Ns[@]}"; do
    for j in "${Ms[@]}"; do
	res=$(./program.3.9 "${i}" "${j}")
	echo "N=${i} M=${j} node=${res}"
    done
done
