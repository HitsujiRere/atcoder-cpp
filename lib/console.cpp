#include <bits/stdc++.h>

// clang-format off
struct console {
    std::ostream &_os;
    console(std::ostream &os) : _os(os) {}
    // print values with separating by space
    constexpr console& print() { return *this; }
    template <class Head> console& print(Head &&head) { _print(*this, head); return *this; }
    template <class Head, class... Tail> console& print(Head &&head, Tail &&...tail) { _print(*this, head); _os << " "; return print(tail...); }
    // print values without separating
    constexpr console& print_raw() { return *this; }
    template <class Head> console& print_raw(Head &&head) { _print(*this, head); return *this; }
    template <class Head, class... Tail> console& print_raw(Head &&head, Tail &&...tail) { _print(*this, head); return print_raw(tail...); }
    // print and insert new line
    constexpr console& println() { return *this; }
    template <class... Args> console& println(Args &&...args) { print(args...); _os << "\n"; return *this; }
#ifdef DEJI_VALID_DEBUGGER
    // print by debug style
    constexpr console& debug() { return *this; }
    template <class Head> console& debug(Head &&head) { _debug(*this, head); return *this; }
    template <class Head, class... Tail> console& debug(Head &&head, Tail &&...tail) { _debug(*this, head); _os << ", "; return debug(tail...); }
    // print by debug style and insert new line
    constexpr void debugln() {}
    template <class... Args> console& debugln(Args &&...args) { debug_tab(); debug(args...); _os << "\n"; return *this; }
    // tab
    int _tab = 0;
    console tab(int tab) { auto c = *this; c._tab = tab; return c; }
    constexpr console &debug_tab() { for (; _tab > 0; --_tab) { print("|   "); } return *this; }
#else
    template <class... Args> console& debug([[maybe_unused]] Args &&...args) { return *this; }
    template <class... Args> console& debugln([[maybe_unused]] Args &&...args) { return *this; }
    console &tab(int tab) { return *this; }
    constexpr console &debug_tab() { return *this; }
#endif
};
template <class T> void _print(console &c, T x) { c._os << x; }
struct str_dbgraw {
    std::string txt;
    template <class... Args>
    str_dbgraw(const Args... args): txt(join(args...)) {}
    static std::string join() { return ""; }
    template <class... Tail> static std::string join(const std::string &&head, Tail &&...tail) { return head + join(tail...); }
    template <class... Tail> static std::string join(const char *head, Tail &&...tail) { return std::string(head) + join(tail...); }
    template <class Head, class... Tail> static std::string join(Head &&head, Tail &&...tail) { return std::to_string(head) + join(tail...); }
};
template <class T> struct var_dbg { std::string name; T var; };
#ifdef DEJI_VALID_DEBUGGER
#define debug$(...) debug(str_dbgraw("DEBUG ", __func__, ":", __LINE__), __VA_ARGS__)
#define debugln$(...) debugln(str_dbgraw("DEBUG ", __func__, ":", __LINE__), __VA_ARGS__)
#define v$(x) (var_dbg<typeof(x)>{#x, x})
#else
#define debug$(...) debug()
#define debugln$(...) debugln()
#define v$(x) 0
#endif
void _debug(console &c, int x) { c.print(x); }
void _debug(console &c, long long int x) { c.print(x); }
void _debug(console &c, float x) { c.print(x); }
void _debug(console &c, double x) { c.print(x); }
void _debug(console &c, char x) { c.print_raw("'", x, "'"); }
void _debug(console &c, std::string x) { c.print_raw('"', x, '"'); }
void _debug(console &c, const char *x) { _debug(c, std::string(x)); }
void _debug(console &c, str_dbgraw x) { c.print(x.txt); }
template <class T> void _debug(console &c, var_dbg<T> x) { c.print_raw(x.name, ": ", x.var); }
template <class T> void _debug(console &c, const std::vector<T> &x) { c.print_raw("["); for (size_t i = 0; i < x.size(); ++i) { if (i > 0) { c.print_raw(", "); } c.print(x[i]); } c.print_raw("]"); }
// clang-format on

console out{std::cout};
console err{std::cerr};
