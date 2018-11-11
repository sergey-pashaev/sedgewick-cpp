#!/usr/bin/env bash

set -eu

if [ $# -lt 2 ]; then
    exit 1
fi

curdir=`pwd -P`
prg="$1"
travis=$2
input=$3
args=${@:4}
output="${input%.in}.out"

tmpdir=`mktemp -d $prg.tmp.XXXXXX`
trap "rm -r $tmpdir" EXIT

(cd $tmpdir && kcov --coveralls-id="$travis" --exclude-pattern=/usr/include,thirdparty "${curdir}/report/" $prg $args < $input > out)
diff -u $tmpdir/out $output
