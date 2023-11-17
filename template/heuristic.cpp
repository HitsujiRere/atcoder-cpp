// clang-format off
// check Overflow
#ifdef DEJI_VALID_DEBUGGER
#define _GLIBCXX_DEBUG
#endif
// include all std
#include <bits/stdc++.h>
// AtCoder Library v1.5.1; https://github.com/atcoder/ac-library
#include <atcoder/all>
// debugger
#ifdef DEJI_VALID_DEBUGGER
#include "debugger.hpp"
#else
#define debug(...)
#define debugdo(...)
#define debugtab(...)
#define test_eq(x, y)
#endif
// for alias
#define range(i, A, B) for (ll i = (ll)(A); i < (ll)(B); ++i)
#define rrange(i, A, B) for (ll i = (ll)(B)-1; i >= (ll)(A); --i)
#define rep(i, N) range(i, 0, N)
#define rrep(i, N) rrange(i, 0, N)
// type alias
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
template <class T> using vec = vector<T>;
template <class T> using vec2 = vector<vec<T>>;
template <class T> using vec3 = vector<vec2<T>>;
template <class T> using priority_greater_queue = priority_queue<T, vector<T>, greater<T>>;
// number alias
constexpr ll INFL = numeric_limits<ll>::max() / 4;
constexpr array<ll, 4> DX4 = {1, 0, -1, 0};
constexpr array<ll, 4> DY4 = {0, 1, 0, -1};
constexpr array<ll, 8> DX8 = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr array<ll, 8> DY8 = {0, 1, 1, 1, 0, -1, -1, -1};
// new vector
template <class T> vec2<T> newvec2(size_t n2, size_t n1, T x = T()) { return vec2<T>(n2, vec<T>(n1, x)); }
template <class T> vec3<T> newvec3(size_t n3, size_t n2, size_t n1, T x = T()) { return vec3<T>(n3, vec2<T>(n2, vec<T>(n1, x))); }
// input/output
template <class T> istream &operator>>(istream &is, vector<T> &data) { for (T &in : data) is >> in; return is; }
template <class T, class U> istream &operator>>(istream &is, pair<T, U> &data) { return is >> data.first >> data.second; }
ostream &operator<<(ostream &os, atcoder::modint998244353 data) { return os << data.val(); }
ostream &operator<<(ostream &os, atcoder::modint1000000007 data) { return os << data.val(); }
// functions
template <class T> vector<T> &operator--(vector<T> &data) { for (T &x : data) x--; return data; }
string yes_no(bool x) { return x ? "Yes" : "No"; }
ll or_not(ll x) { return x != INFL ? x : -1; }
template <class T> bool chmax(T &a, const T b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

/*****/

using system_time = chrono::time_point<chrono::system_clock>;

ll elapsed_msec(system_time start) {
    auto end = chrono::system_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

random_device seed_gen;
mt19937_64 engine(seed_gen());
system_time START_TIME;

/*****/

ll N;

#ifdef DEJI_DEBUG_INOUT
ll M;
#endif

void Input() {
    cin >> N;

#ifdef DEJI_DEBUG_INOUT
    cin >> M;
#endif
}

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
