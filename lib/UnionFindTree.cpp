#include <bits/stdc++.h>
using namespace std;

// Union Find Tree
struct UnionFindTree {
    // size[x] = 集合のサイズ
    vector<int> size;
    // parents[x] = xの親
    vector<int> parents;

    // n個の木を作成
    UnionFindTree(int n) {
        assert(n >= 0);
        size.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) makeTree(i);
    }

    // xとyが同じ集合にいるか。計算量はO(α(n))
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }

    // xとyを同じ集合にする。計算量はO(α(n))
    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parents[y] = x;
        size[x] += size[y];
        return true;
    }

    // xを含む木の根を求める
    int findRoot(int x) {
        assert(x >= 0);
        if (x != parents[x]) parents[x] = findRoot(parents[x]);
        return parents[x];
    }

    // xを含む集合の要素数を求める
    int treeSize(int x) { return size[findRoot(x)]; }

   private:
    // xを根とする木を作成する
    void makeTree(int x) {
        assert(x >= 0);
        parents[x] = x;
        size[x] = 1;
    }
};
