#include <bits/stdc++.h>
using namespace std;

// Union Find Tree
template <class T>
struct UnionFindTree {
    // 集合のサイズ
    vector<int> sizes;
    // xの親
    vector<int> parent;
    // 重み
    vector<T> diffweights;

    // n個の木を作成
    UnionFindTree(int n) {
        assert(n >= 0);
        sizes.resize(n);
        parent.resize(n);
        diffweights.resize(n);
        for (int i = 0; i < n; i++) makeTree(i);
    }

    // xを含む木の根を求める
    int findRoot(int x) {
        assert(x >= 0);
        compress();
        return parent[x];
    }

    // xを含む集合の要素数を求める
    int treeSize(int x) { return sizes[findRoot(x)]; }

    // 重さを求める
    T weight(int x) {
        compress();
        return diffweights[x];
    }

    // xとyが同じ集合にいるか。計算量はO(α(n))
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }

    // xとyを同じ集合にする。計算量はO(α(n))
    bool unite(int x, int y, T w) {
        w += weight(x);
        w -= weight(y);
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (sizes[x] < sizes[y]) {
            swap(x, y);
            w *= -1;
        }
        parent[y] = x;
        sizes[x] += sizes[y];
        diffweights[y] += w;
        return true;
    }

   private:
    // xを根とする木を作成する
    void makeTree(int x) {
        assert(x >= 0);
        parent[x] = x;
        sizes[x] = 1;
        diffweights[x] = 0;
    }

    // 圧縮する
    void compress(int x) {
        assert(x >= 0);
        if (x == parent[x]) return;
        if (parent[x] == parent[parent[x]]) return;
        const int root = findRoot(parent[x]);
        diffweights[x] += diffweights[parent[x]];
        parent[x] = root;
    }
};
