#include <bits/stdc++.h>
using namespace std;

// 行列
template <class T>
struct Matrix {
    vector<vector<T>> A;
    Matrix(const vector<vector<T>> &A) : A(A) {
        assert(A.size() >= 1 && A[0].size() >= 1);
        assert(all_of(A.begin(), A.end(),
                      [&](const vector<T> &a) { return A[0].size() == a.size(); }));
    }
    Matrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) { assert(n >= 1 && m >= 1); }
    Matrix(size_t n) : A(n, vector<T>(n, 0)) { assert(n >= 1); };
    size_t height() const { return A.size(); }
    size_t width() const { return A[0].size(); }
    inline const vector<T> &operator[](int i) const { return A.at(i); }
    inline vector<T> &operator[](int i) { return A.at(i); }
    static Matrix I(size_t n) {
        Matrix mat(n);
        for (size_t i = 0; i < n; i++) mat[i][i] = 1;
        return mat;
    }
    Matrix &operator+=(const Matrix &B) {
        assert(height() == B.height() && width() == B.width());
        size_t n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];
        return *this;
    }
    Matrix &operator-=(const Matrix &B) {
        assert(height() == B.height() && width() == B.width());
        size_t n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];
        return *this;
    }
    Matrix &operator*=(const Matrix &B) {
        assert(width() == B.height());
        size_t n = height(), m = B.width(), p = width();
        vector<vector<T>> C(n, vector<T>(m, 0));
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                for (size_t k = 0; k < p; k++) C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        A.swap(C);
        return *this;
    }
    Matrix &operator^=(long long int k) {
        assert(k >= 0);
        Matrix B = Matrix::I(height());
        while (k > 0) {
            if (k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return *this;
    }
    Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }
    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }
    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }
    Matrix operator^(const long long int k) const { return (Matrix(*this) ^= k); }
    T determinant() const {
        Matrix B(*this);
        assert(width() == height());
        T ret = 1;
        for (int i = 0; i < width(); i++) {
            int idx = -1;
            for (int j = i; j < width(); j++)
                if (B[j][i] != 0) idx = j;
            if (idx == -1) return (0);
            if (i != idx) {
                ret *= -1;
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T vv = B[i][i];
            for (int j = 0; j < width(); j++) B[i][j] /= vv;
            for (int j = i + 1; j < width(); j++) {
                T a = B[j][i];
                for (int k = 0; k < width(); k++) B[j][k] -= B[i][k] * a;
            }
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, Matrix &p) {
        size_t n = p.height(), m = p.width();
        os << "[";
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++) os << p[i][j] << (j + 1 == m ? "; " : ", ");
        os << "]";
        return os;
    }
};
