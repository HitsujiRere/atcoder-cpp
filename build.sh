g++ -std=gnu++17 -Wall -Wextra -o $1 -Ilib/ -Ilib/ac-library $1.cpp -DDEBUG_BUILD

./$1
