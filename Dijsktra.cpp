#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // start = node 1

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, numeric_limits<int>::max());
    dist[1] = 0;
    pq.push({0, 1}); // {jarak, node}

    while(!pq.empty()) {
        auto [d, u] = pq.top(); 
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dist[i] == numeric_limits<int>::max()) cout << -1 << " ";
        else cout << dist[i] << " ";
    }

    return 0;
}