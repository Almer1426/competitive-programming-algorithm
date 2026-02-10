#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> a;
vector<int> tree;

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    return;
}

void update(int node, int start, int end, int idx, int val) {
    if(start == end) {
        a[idx] = val;
        tree[node] = val;
    }
    else {
        int mid = (start + end) / 2;
        if(start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        }
        else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    return;
}

int query(int node, int start, int end, int l, int r) {
    if(r < start || l > end) return 0;
    if(l <= start && r >= end) return tree[node];
    
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    
    return p1 + p2;
}

signed main() {
    cin >> n;

    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    tree.resize(4 * n + 1);
    build(1, 0, n - 1);

    int q;
    cin >> q;

    while(q--) {
        int qx;
        cin >> qx;

        if(qx == 1) {
            int x, y;
            cin >> x >> y;
            update(1, 0, n - 1, x - 1, y);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << ">> ";
            cout << query(1, 0, n - 1, x - 1, y - 1) << endl;
        }
    }

    return 0;
}