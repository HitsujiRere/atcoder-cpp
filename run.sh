echo "Compiling..."
g++ -std=gnu++17 -O2 -Wall -Wextra -o $1 -Ilib/ -Ilib/ac-library $1.cpp
echo "Compiled!"
./$1