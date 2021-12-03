#!/bin/bash

set -e

cd ./build/tests/
export GTEST_COLOR=1 && ctest --extra-verbose
