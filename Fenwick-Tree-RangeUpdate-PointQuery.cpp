#include <bits/stdc++.h>
using namespace std;

struct RangeUpdatePointQueryBIT {
    int n;
    vector<long long> tree;

    RangeUpdatePointQueryBIT(int n) : n(n), tree(n + 1, 0) {}

    void _add(int i, long long val) {
        for (; i <= n; i += i & -i) tree[i] += val;
    }

    void range_add(int l, int r, long long val) {
        _add(l, val);
        _add(r + 1, -val);
    }

    long long get_val(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};