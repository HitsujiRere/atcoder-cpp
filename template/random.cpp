#include <bits/stdc++.h>
using namespace std;

int main() {
    std::random_device rnd;
    std::mt19937 mt(rnd());

    std::uniform_int_distribution<int> rand(1, 100);
    cout << rand(mt) << endl;

    return 0;
}
