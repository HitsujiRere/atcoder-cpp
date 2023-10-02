#!/bin/sh
dirs=`find $2/in/* -maxdepth 0 -type f`
g++ -std=gnu++17 -O2 -Wall -Wextra -o $1_pro -Ilib/ -Ilib/ac-library $1.cpp
sum=0
for dir in $dirs;
do
    score=`cat $2/in/${dir##*/} $2/out/${dir##*/} | ./$1_pro`
    echo $dir: $score
    sumscore=$(($sumscore+$score))
done
echo Sum: $sumscore