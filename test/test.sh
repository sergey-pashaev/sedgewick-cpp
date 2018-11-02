#!/usr/bin/env bash

set -eu

if [ $# -ne 2 ]; then
    exit 1
fi

curdir=`pwd -P`
prg="$1"
input="$2"
output="${input%.in}.out"

tmpdir=`mktemp -d $prg.tmp.XXXXXX`
trap "rm -r $tmpdir" EXIT

(cd $tmpdir && $prg < $input > out)
diff -u $tmpdir/out $output
