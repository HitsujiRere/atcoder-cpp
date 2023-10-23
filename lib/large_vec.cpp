#include <bits/stdc++.h>

template <class T>
using vec4 = std::vector<vec3<T>>;
template <class T>
using vec5 = std::vector<vec4<T>>;

template <class T>
vec4<T> newVec4(size_t n4, size_t n3, size_t n2, size_t n1, T x = T()) {
    return vec4<T>(n4, vec3<T>(n3, vec2<T>(n2, vec<T>(n1, x))));
}
template <class T>
vec5<T> newVec5(size_t n5, size_t n4, size_t n3, size_t n2, size_t n1,
                T x = T()) {
    return vec5<T>(n5, vec4<T>(n4, vec3<T>(n3, vec2<T>(n2, vec<T>(n1, x)))));
}
