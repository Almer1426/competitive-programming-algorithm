#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() ios::sync_with_stdio(0); cin.tie(0);

void solve(int tc) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n + 1, 0);

    vector<int> key(n + 1, numeric_limits<int>::min());
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], key[a[i - 1]] + i);
        key[a[i - 1]] = max(key[a[i - 1]], dp[i - 1] - (i - 1));
    }
    
    cout << dp[n] << endl;

    return; 
}

signed main() {
    fastIO();
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) solve(tc);
    return 0;
}