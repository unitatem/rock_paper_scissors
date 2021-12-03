#!/bin/bash

targets="all"

if [ ! -z "$@" ]; then
  targets="$@"
fi

mkdir -p build && cmake . -B./build && cmake --build build --target "$targets"
