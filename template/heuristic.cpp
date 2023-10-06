// check Overflow
#ifdef DEBUG_BUILD
#define _GLIBCXX_DEBUG
#endif

// include all std
#include <bits/stdc++.h>

// AtCoder Library v1.5.1
// https://github.com/atcoder/ac-library
#include <atcoder/all>

// debugger
#ifdef DEBUG_BUILD
#include "debugger.hpp"
#else
#define debug(...)
#define debugdo(...)
#define debugtab(...)
#define test_eq(x, y)
#endif

// for alias
#define range(i, A, B) for (ll i = (ll)(A); i < (ll)(B); i++)
#define rrange(i, A, B) for (ll i = (ll)(B)-1; i >= (ll)(A); i--)
#define rep(i, N) range(i, 0, N)
#define rrep(i, N) rrange(i, 0, N)

// type alias
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
template <class T>
using vec = std::vector<T>;
template <class T>
using vec2 = std::vector<vec<T>>;
template <class T>
using vec3 = std::vector<vec2<T>>;
template <class T>
using priority_greater_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

// number alias
constexpr ll INFL = std::numeric_limits<ll>::max() / 4;
constexpr array<ll, 4> DX4 = {1, 0, -1, 0};
constexpr array<ll, 4> DY4 = {0, 1, 0, -1};
constexpr array<ll, 8> DX8 = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr array<ll, 8> DY8 = {0, 1, 1, 1, 0, -1, -1, -1};

// new vector
template <class T>
vec2<T> newVec2(size_t A, size_t B, T a = T()) {
    return vec2<T>(A, vec<T>(B, a));
}
template <class T>
vec3<T> newVec3(size_t A, size_t B, size_t C, T a = T()) {
    return vec3<T>(A, vec2<T>(B, vec<T>(C, a)));
}

// input
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &data) {
    for (T &in : data) is >> in;
    return is;
}
template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &data) {
    return is >> data.first >> data.second;
}

// functions
string yes_no(bool x) { return x ? "Yes" : "No"; }
template <class T>
bool chmax(T &a, const T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, const T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
ll powll(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

/*****/

using system_time = chrono::time_point<chrono::system_clock>;

ll elapsed_msec(system_time start) {
    auto end = chrono::system_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

random_device seed_gen;
mt19937_64 engine(seed_gen);
system_time START_TIME;

constexpr int MOD = 1000000007;

/*****/

void Input() {}

void Output() {}

ll Score() {}

/*****/

void Main() {
    START_TIME = chrono::system_clock::now();

    Input();

    Output();

    cerr << elapsed_msec(START_TIME) << "msec" << endl;
}

/*****/

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    std::cerr << std::fixed << std::setprecision(10);
    Main();
    std::cout << std::flush;
    std::cerr << std::flush;
    return 0;
}
