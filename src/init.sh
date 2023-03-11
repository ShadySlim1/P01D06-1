#!/bin/bash

#file="$1"
file="pong.c"
executable="run"
gcc -o $executable $file
./$executable
rm run


