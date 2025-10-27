#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
 
    vector<int> dp(x + 1, 0); dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= x; j++) {
            if(a[i] <= j) dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
 
    cout << dp[x] << endl;

    return 0;
}