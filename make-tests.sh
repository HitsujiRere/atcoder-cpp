#!/bin/sh
dirs=`find $2/in/* -maxdepth 0 -type f`
g++ -std=gnu++17 -O2 -Wall -Wextra -o $1 -Ilib/ -Ilib/ac-library $1.cpp
for dir in $dirs;
do
    echo $dir
    ./$1 < $dir > $2/out/${dir##*/}
done