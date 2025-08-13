#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> a;
vector<int> tree;
vector<int> lazy;

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

void pushDown(int node, int start, int end) {
	if(lazy[node] == 0) return;
	
	int val = lazy[node];
	int mid = (start + end) / 2;
	
	tree[2 * node] += (mid - start + 1) * val;
	tree[2 * node + 1] += (end - (mid + 1) + 1) * val;
	
	lazy[2 * node] += val;
	lazy[2 * node + 1] += val;
	lazy[node] = 0;
	
	return;
}

void updateRange(int node, int start, int end, int l, int r, int val) {
	if(r < start || l > end) return;
	if(l <= start && end <= r) {
		tree[node] += (end - start + 1) * val;
		lazy[node] += val;
		return;
	}
	
	pushDown(node, start, end);
	
	int mid = (start + end) / 2;
	updateRange(2 * node, start, mid, l, r, val);
	updateRange(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];

    return;
}

int queryRange(int node, int start, int end, int l, int r) {
    if(r < start || l > end) return 0;
    if(l <= start && end <= r) return tree[node];
    
    pushDown(node, start, end);
    
    int mid = (start + end) / 2;
    int p1 = queryRange(2 * node, start, mid, l, r);
    int p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    
    return p1 + p2;
}

signed main() {
    cin >> n;

    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    tree.resize(4 * n + 1, 0);
    lazy.resize(4 * n + 1, 0);
    build(1, 0, n - 1);

    int q;
    cin >> q;

    while(q--) {
        int qx;
        cin >> qx;

        if(qx == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            updateRange(1, 0, n - 1, x - 1, y - 1, z);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << ">> ";
            cout << queryRange(1, 0, n - 1, x - 1, y - 1) << endl;
        }
    }

    return 0;
}

/*
4
1 5 2 8
*/
