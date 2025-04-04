#!/bin/sh
dirs=`find $2/in/* -maxdepth 0 -type f`
# g++ -std=gnu++17 -O2 -Wall -Wextra -o $1_pro -Ilib/ -Ilib/ac-library $1.cpp
g++ -std=gnu++17 -O2 -Wall -Wextra -o $1_pro -Ilib/ -Ilib/ac-library $1.cpp -DDEJI_DEBUG_INOUT
mkdir -p $2/out/
echo -n > $2/results.txt
for dir in $dirs;
do
    echo "-----" >> $2/results.txt
    echo $dir "->" $2/out/${dir##*/} >> $2/results.txt
    ./$1_pro < $dir > $2/out/${dir##*/} 2>> $2/results.txt
done