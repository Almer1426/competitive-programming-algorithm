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
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> e;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        e.push_back({w, u, v});
    }
    sort(e.begin(), e.end());

    int ans = 0;
    
    DSU dsu(n);
    for(auto [w, u, v] : e) {
        if(dsu.unite(u, v)) {
            ans += w;
        }
    }

    cout << ans << endl;

    return 0;
}