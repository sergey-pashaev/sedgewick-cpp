#!/usr/bin/env bash

echo "Running pre-commit hook"

# stash unstaged files
STASH_NAME="pre-commit-$(date +%s)"
git stash save -q --keep-index $STASH_NAME

# run tests
./scripts/run-tests.sh

# restore stashed files
STASH_NUM=$(git stash list | grep $STASH_NAME | sed -re 's/stash@\{(.*)\}.*/\1/')
if [ -n "$STASH_NUM" ]
    then
    git stash pop -q stash@{$STASH_NUM}
fi

if [ $? -ne 0 ]; then
    echo "Tests must pass before commit!"
    exit 1
fi
