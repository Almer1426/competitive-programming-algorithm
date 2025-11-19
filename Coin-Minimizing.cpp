#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(x + 1, numeric_limits<int>::max()); dp[0] = 0;

    for(int i = 0; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j] <= i && dp[i - a[j]] != numeric_limits<int>::max()) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    if(dp[x] != numeric_limits<int>::max()) cout << dp[x] << endl;
    else cout << -1 << endl;

    return 0;
}