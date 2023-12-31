#include <bits/stdc++.h>

// clang-format off
struct range {
   public:
    using I = long long int;
    struct iterator {
       private:
        I _cur;
        const I _step;
       public:
        constexpr iterator(const I cur, const I step) : _cur(cur), _step(step) {}
        constexpr I operator*() { return _cur; }
        constexpr iterator &operator++() { _cur += _step; return *this; }
        constexpr iterator operator++(int) { auto tmp = *this; _cur += _step; return tmp; }
        constexpr iterator &operator--() { _cur -= _step; return *this; }
        constexpr iterator operator--(int) { auto tmp = *this; _cur -= _step; return tmp; }
        constexpr bool operator==(const iterator &v) { return _cur == v._cur && _step == v._step; }
        constexpr bool operator!=(const iterator &v) { return !(*this == v); }
    };
    constexpr range(const I end) : _start(0), _end(end), _step(1) {}
    constexpr range(const I start, const I end) : _start(start), _end(end), _step(1) {}
    constexpr range(const I start, const I end, const I step) : _start(start), _end(normalized_end(start, end, step)), _step(step) {}
    constexpr iterator begin() { return {_start, _step}; }
    constexpr iterator end() { return {_end, _step}; }
    constexpr range rev() { return {_end - _step, _start - _step, -_step}; }
   private:
    const I _start;
    const I _end;
    const I _step;
    constexpr static I normalized_end(I start, I end, I step) { if ((end - start) % step == 0) { return end; } return end + step - (end - start) % step; }
};
// clang-format on
