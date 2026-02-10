#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;

        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += b;

        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int componentSize(int x) {
        return size[x];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--) {
        string type;
        cin >> type;
        
        if (type == "union") {
            int a, b;
            cin >> a >> b;
            dsu.unite(a, b);
        }
        else if (type == "check") {
            int a, b;
            cin >> a >> b;
            cout << (dsu.same(a, b) ? "YES\n" : "NO\n");
        }
        else if (type == "size") {
            int a;
            cin >> a;
            cout << dsu.componentSize(a) << "\n";
        }
    }

    return 0;
}