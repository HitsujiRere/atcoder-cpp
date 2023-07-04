if [ -e $1 ]; then
    timeExe=`date +%Y%m%d%H%M%S -r $1`
else
    timeExe="0"
fi
Cpp=`date +%Y%m%d%H%M%S -r $1.cpp`
if [ $timeCpp -ge $timeExe ]; then
    echo "Compiling..."
    g++ -std=gnu++17 -O2 -Wall -Wextra -o $1 -Ilib/ -Ilib/ac-library $1.cpp
    echo "Compiled!"
else
echo "Run:"
./$1