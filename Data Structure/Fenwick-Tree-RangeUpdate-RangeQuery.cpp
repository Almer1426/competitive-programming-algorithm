#include <bits/stdc++.h>
using namespace std;

struct RangeRangeBIT {
    int n;
    vector<long long> B1, B2;

    RangeRangeBIT(int n) : n(n), B1(n + 1, 0), B2(n + 1, 0) {}

    void _add(vector<long long>& b, int i, long long val) {
        for (; i <= n; i += i & -i) b[i] += val;
    }

    long long _query(vector<long long>& b, int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) sum += b[i];
        return sum;
    }

    void range_add(int l, int r, long long val) {
        _add(B1, l, val);
        _add(B1, r + 1, -val);
        _add(B2, l, l * val);
        _add(B2, r + 1, -(r + 1) * val);
    }

    long long prefix_query(int x) {
        return _query(B1, x) * (x + 1) - _query(B2, x);
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return prefix_query(r) - prefix_query(l - 1);
    }
};