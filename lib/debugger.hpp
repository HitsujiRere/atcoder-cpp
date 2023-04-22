#include <bits/stdc++.h>

// Debug variables
#define debug(...)                                                \
    std::cerr << "DEBUG " << __func__ << ":" << __LINE__ << " | " \
              << debug_os(__VA_ARGS__) << std::endl

// Run in debug-mode
#define debugdo(...) \
    do {             \
        __VA_ARGS__  \
    } while (0)

// Debug variables with tabs
#define debugtab(tab, ...)  \
    do {                    \
        write_tab(tab);     \
        debug(__VA_ARGS__); \
    } while (0)

// Test x == y
#define test_eq(x, y)                                                     \
    do {                                                                  \
        const auto X = (x);                                               \
        const auto Y = (y);                                               \
        if (X != Y)                                                       \
            std::cerr << "ERROR " << __func__ << ":" << __LINE__ << " | " \
                      << #x << ": " << X << " != " << #y << ": " << Y     \
                      << std::endl;                                       \
    } while (0)

/*****/

#define GET_MACRO4(_1, _2, _3, _4, NAME, ...) NAME
#define debug_os(...)                                                   \
    GET_MACRO4(__VA_ARGS__, debug_os4, debug_os3, debug_os2, debug_os1) \
    (__VA_ARGS__)

#define debug_os1(val) #val << " : " << (val)
#define debug_os2(val, ...) \
#val << ": " << (val) << " | " << debug_os1(__VA_ARGS__)
#define debug_os3(val, ...) \
#val << ": " << (val) << " | " << debug_os2(__VA_ARGS__)
#define debug_os4(val, ...) \
#val << ": " << (val) << " | " << debug_os3(__VA_ARGS__)

void write_tab(int tab) {
    while (tab > 0) {
        std::cerr << "|   ";
        tab--;
    }
}

template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &val) {
    return os << "(" << val.first << ", " << val.second << ")";
}

template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &data) {
    if (data.empty()) {
        return os << "{ }";
    }
    os << "{";
    for (size_t i = 0; i < data.size(); ++i) {
        // if (data.at(i) == std::numeric_limits<long long>::max() / 4) {
        //     os << "INF" << (i == data.size() - 1 ? "}" : ", ");
        // } else {
        os << data.at(i) << (i == data.size() - 1 ? "}" : ", ");
        // }
    }
    return os;
}

template <class T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &data) {
    os << "{";
    for (size_t i = 0; i < N; ++i) {
        // if (data.at(i) == std::numeric_limits<long long>::max() / 4) {
        //     os << "INF" << (i == data.size() - 1 ? "}" : ", ");
        // } else {
        // os << (data.at(i) ? 1 : 0);
        os << data.at(i) << (i == data.size() - 1 ? "}" : ", ");
        // }
    }
    os << "}";
    return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &data) {
    if (data.empty()) {
        return os << "{ }";
    }
    auto dataItr = data.begin();
    os << "{" << *dataItr;
    ++dataItr;
    for (; dataItr != data.end(); ++dataItr) {
        os << ", " << *dataItr;
    }
    os << "}";
    return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const std::multiset<T> &data) {
    if (data.empty()) {
        return os << "{ }";
    }
    auto dataItr = data.begin();
    os << "{" << *dataItr;
    ++dataItr;
    for (; dataItr != data.end(); ++dataItr) {
        os << ", " << *dataItr;
    }
    os << "}";
    return os;
}

template <class Key, class T>
std::ostream &operator<<(std::ostream &os, const std::map<Key, T> &data) {
    if (data.empty()) {
        return os << "{ }";
    }
    auto dataItr = data.begin();
    os << "{" << *dataItr;
    ++dataItr;
    for (; dataItr != data.end(); ++dataItr) {
        os << ", " << *dataItr;
    }
    os << "}";
    return os;
}
