#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    int n;
    vector<long long> tree;

    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, long long val) {
        for (; i <= n; i += i & -i) {
            tree[i] += val;
        }
    }

    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};