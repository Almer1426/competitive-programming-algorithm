#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> tin, tout;
int timer = 0;

void dfs_flatten(int u, int p) { // u = current node, p = parent
    timer++;
    tin[u] = timer; // Catat waktu masuk
    
    for(int v : adj[u]) {
        if(v != p) {
            dfs_flatten(v, u);
        }
    }
    
    tout[u] = timer; // Catat waktu keluar (timer terakhir di subtree ini)
}

signed main() {
    int n = 5e5;

    adj.resize(n);
    tin.resize(n);
    tout.resize(n);

    return 0;
}