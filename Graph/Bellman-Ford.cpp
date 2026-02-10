#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int INF = 1e15;

struct Edge {
    int u, v, w;
};

signed main() {
    int n, m, start;
    cin >> n >> m >> start;
    start--;

    vector<Edge> edges(m);
    for(int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    vector<int> dist(n, INF);
    dist[start] = 0;

    for(int i = 0; i < n - 1; i++) {
        bool updated = false;
        for(auto [u, v, w] : edges) {
            if(dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }

        if(!updated) break;
    }

    vector<int> inNegativeCycle(n, 0);
    for(auto [u, v, w] : edges) {
        if(dist[u] < INF && dist[u] + w < dist[v]) {
            inNegativeCycle[v] = 1;
        }
    }

    queue<int> que;
    for(int i = 0; i < n; i++) {
        if(inNegativeCycle[i]) que.push(i);
    }

    vector<vector<int>> adj(n);
    for(auto [u, v, w] : edges) {
        adj[u].push_back(v);
    }

    while(!que.empty()) {
        auto curr = que.front(); que.pop();
        for(auto next : adj[curr]) {
            if(!inNegativeCycle[next]) {
                inNegativeCycle[next] = 1;
                que.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (inNegativeCycle[i]) cout << -1 << endl; // bagian dari siklus negatif
        else if (dist[i] == INF) cout << -1 << endl; // tidak dapat dicapai
        else cout << dist[i] << "\n";
    }

    return 0;
}