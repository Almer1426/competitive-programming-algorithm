#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = (int) 1e9 + 7;

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> prev(m + 2, 0), cur(m + 2, 0);
    if(a[1]) prev[a[1]] = 1;
    else for(int j = 1; j <= m; j++) prev[j] = 1;

    for(int i = 2; i <= n; i++) {
        fill(cur.begin(), cur.end(), 0);

        if(a[i]) {
            int j = a[i];
            cur[j] = (prev[j - 1] + prev[j] + prev[j + 1]) % MOD;
        }
        else {
            for(int j = 1; j <= m; j++) cur[j] = (prev[j - 1] + prev[j] + prev[j + 1]) % MOD;
        }

        swap(prev, cur);
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) ans = (ans + prev[j]) % MOD;
    
    cout << ans << endl;

    return 0;
}
