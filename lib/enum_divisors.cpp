#include <bits/stdc++.h>
using namespace std;

// 約数列挙
template <class T>
vector<T> enum_divisors(T n) {
    vector<T> res;
    for (T i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (n != i * i) res.push_back(n / i);
        }
    }
    return res;
}
