#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 素因数分解する O(sprt(n))
vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        ll ex = 0;  // 指数
        while (n % i == 0) {
            ++ex;
            n /= i;
        }
        res.push_back({i, ex});
    }
    if (n != 1) res.push_back({n, 1});
    return res;
}
