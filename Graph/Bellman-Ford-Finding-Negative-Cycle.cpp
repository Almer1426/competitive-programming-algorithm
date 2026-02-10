#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = (int) 1e16;

signed main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> e(m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u - 1, v - 1, w};
    }

    vector<int> dist(n, INF); dist[0] = 0;
    vector<int> backtrack(n, -1);
    int initialCycle = -1;

    for(int i = 0; i < n; i++) {
        initialCycle = -1;
        for(auto [u, v, w] : e) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                backtrack[v] = u;
                initialCycle = v;
            }
        }
    }

    if(initialCycle == -1) {
        cout << "NO\n";
        return;
    }
    else {
        for(int i = 0; i < n; i++) initialCycle = backtrack[initialCycle];
    
        vector<int> cycle;
        for(int i = initialCycle;; i = backtrack[i]) {
            cycle.push_back(i);
            if(i == initialCycle && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
    
        cout << "YES\n";
        for(auto x : cycle) cout << x + 1 << " ";
        cout << endl;
    }

    return 0;
}