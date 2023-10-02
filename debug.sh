if [ -e $1_dev ]; then
    timeExe=`date +%Y%m%d%H%M%S -r $1_dev`
else
    timeExe="0"
fi
timeCpp=`date +%Y%m%d%H%M%S -r $1.cpp`
if [ $timeCpp -ge $timeExe ]; then
    echo "Compiling..." >&2
    g++ -std=gnu++17 -O2 -Wall -Wextra -o $1_dev -Ilib/ -Ilib/ac-library $1.cpp -DDEBUG_BUILD
    echo "Compiled!" >&2
fi
echo "Run (develop mode):" >&2
./$1_dev