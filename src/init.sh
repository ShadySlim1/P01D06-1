#!/bin/bash

#file="$1"
file="pong.c"
executable="run"
clang-format -i *.c
gcc -o $executable $file
./$executable
rm run


