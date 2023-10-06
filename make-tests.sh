#!/bin/sh
dirs=`find $2/in/* -maxdepth 0 -type f`
g++ -std=gnu++17 -O2 -Wall -Wextra -o $1_pro -Ilib/ -Ilib/ac-library $1.cpp
mkdir -p $2/out/
for dir in $dirs;
do
    echo "-----"
    echo $dir "->" $2/out/${dir##*/}
    ./$1_pro < $dir > $2/out/${dir##*/}
done