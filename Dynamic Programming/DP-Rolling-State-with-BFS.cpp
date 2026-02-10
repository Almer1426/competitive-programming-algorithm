#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define pb push_back

int main() {
    int n;
    cin >> n;

    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];

    string ans = "";

    vector<pii> prev, next;
    vector<vector<int>> vis(n, vi(n, 0));

    prev.pb({0, 0});
    vis[0][0] = 1;
    ans += g[0][0];
    while(!vis[n - 1][n - 1]) {
        char best = 'Z';
        next.clear();

        for(auto [x, y] : prev) {
            if(x + 1 < n) {
                best = min(best, g[x + 1][y]);
            }
            if(y + 1 < n) {
                best = min(best, g[x][y + 1]);
            }
        }

        for(auto [x, y] : prev) {
            if(x + 1 < n && !vis[x + 1][y] && g[x + 1][y] == best) {
                vis[x + 1][y] = 1;
                next.pb({x + 1, y});
            }
            if(y + 1 < n && !vis[x][y + 1] && g[x][y + 1] == best) {
                vis[x][y + 1] = 1;
                next.pb({x, y + 1});
            }
        }

        ans += best;
        swap(prev, next);
    }

    cout << ans << endl;

    return 0;
}