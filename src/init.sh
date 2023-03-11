#!/bin/bash

#file="$1"
file="pong1.c"
executable="run"
gcc -o $executable $file
./$executable
rm run


