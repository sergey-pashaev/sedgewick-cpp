#!/usr/bin/env bash

set -eu

if [ $# -lt 5 ]; then
    exit 1
fi

prg="$1"
input="$2"
coverage_cmd="$3"
coverage_args="$4"
coverage_report_path="$5"
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
    $coverage_cmd ${coverage_args} ${coverage_report_path} ${prg} $args_str < "${input}" > out
    if [ -e "${output}" ]
    then
        diff -u "${tmpdir}/out" "${output}"
    fi
else
    $coverage_cmd ${coverage_args} ${coverage_report_path} ${prg} $args_str
fi
