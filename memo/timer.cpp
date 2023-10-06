#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using system_time = chrono::time_point<chrono::system_clock>;

ll elapsed_msec(system_time start) {
    auto end = chrono::system_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int main() {
    system_time start = chrono::system_clock::now();
    ll msec = elapsed_msec(start);

    return 0;
}
