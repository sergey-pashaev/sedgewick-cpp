#!/usr/bin/env bash

set -eu

if [ $# -lt 2 ]; then
    exit 1
fi

prg="$1"
input="$2"
output="${input%.in}.out"
args="${input%.in}.args"
args_str=""
if [ -e "${args}" ]
then
    args_str=$(cat "${args}")
fi

tmpdir=$(mktemp -d "${prg}.tmp.XXXXXX")
trap 'rm -r ${tmpdir}' EXIT

cd "${tmpdir}"
if [ -e "${input}" ]
then
    ${prg} $args_str < "${input}" > out
    if [ -e "${output}" ]
    then
        diff -u "${tmpdir}/out" "${output}"
    fi
else
    ${prg} $args_str
fi
