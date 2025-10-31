#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

int main() {
    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    vvi dp(n + 1, vi(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
            int y = dp[i - 1][j];
            int z = dp[i][j - 1];
            dp[i][j] = max({x, y, z});
        }
    }

    vector<int> seq;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            seq.push_back(a[i - 1]);
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << dp[n][m] << endl;
    reverse(seq.begin(), seq.end()); for(auto x : seq) cout << x << " ";
    cout << endl;

    return 0;
}