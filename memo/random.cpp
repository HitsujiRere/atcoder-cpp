#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device seed_gen;
    mt19937_64 engine(seed_gen());

    // 1以上100以下の離散一様分布
    uniform_int_distribution<> rand(1, 100);
    cout << rand(engine) << endl;

    return 0;
}
