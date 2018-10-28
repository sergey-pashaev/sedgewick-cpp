#!/usr/bin/env bash

GIT_DIR=$(git rev-parse --git-dir)

ln -sfn ../../scripts/pre-commit.sh $GIT_DIR/hooks/pre-commit
