#include <bits/stdc++.h>
using namespace std;

/*
Problem:
https://tlx.toki.id/problems/compfest-14-scpc-penyisihan/M
*/

#define int long long
#define fastIO() ios::sync_with_stdio(0); cin.tie(0);
#define spc " "
using T = tuple<int, int, int>;

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector<vector<vector<T>>> adj(2, vector<vector<T>>(n));
    for(int i = 0; i < n; i++) adj[0][i].push_back({i, 1, 0});
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[0][u].push_back({v, 0, w});
        adj[1][v].push_back({u, 1, w});
    }

    priority_queue<T, vector<T>, greater<T>> pq;
    vector<vector<int>> dist(2, vector<int>(n, numeric_limits<int>::max()));

    dist[0][0] = 0;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
        auto [d, u, su] = pq.top(); pq.pop();

        if(d > dist[su][u]) continue;

        for(auto [v, sv, w] : adj[su][u]) {
            if(dist[su][u] + w < dist[sv][v]) {
                dist[sv][v] = dist[su][u] + w;
                pq.push({dist[sv][v], v, sv});
            }
        }
    }

    for(int i = 1; i < n; i++) {
        if(dist[1][i] == numeric_limits<int>::max()) cout << -1 << spc;
        else cout << dist[1][i] << spc;
    }

    return; 
}

signed main() {
    fastIO();
    int t = 1;
    for(int tc = 1; tc <= t; tc++) solve(tc);
    return 0;
}