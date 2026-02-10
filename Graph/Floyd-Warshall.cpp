#include <bits/stdc++.h>
using namespace std;

#define int long long
int INF = (int) 1e13;

signed main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) dist[i][i] = 0;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        // cout << ">> ";
        if(dist[u][v] < INF) cout << dist[u][v] << endl;
        else cout << -1 << endl;
    }

    return 0;
}