#!/usr/bin/env bash

set -eu

if [ $# -lt 2 ]; then
    exit 1
fi

curdir=`pwd -P`
prg="$1"
input="$2"
args=${@:3}
output="${input%.in}.out"

tmpdir=`mktemp -d $prg.tmp.XXXXXX`
trap "rm -r $tmpdir" EXIT

(cd $tmpdir && kcov --exclude-pattern=/usr/include,thirdparty "${curdir}/report/" $prg $args < $input > out)
diff -u $tmpdir/out $output
