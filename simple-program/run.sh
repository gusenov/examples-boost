#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

c++ -Wall `find . -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" \
  && "$EXE_FILE"
