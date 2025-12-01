#include <bits/stdc++.h>
using namespace std;

/*
Problem:
https://codeforces.com/problemset/problem/1661/D
*/

#define int long long
#define fastIO() ios::sync_with_stdio(0); cin.tie(0);

void solve(int tc) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    int currentValue = 0;
    int open = 0;
    vector<int> close(n, 0);

    for(int i = n - 1; i >= 0; i--) {
        if(a[i] - currentValue > 0ll) {
            int kCurr = i <= k - 1 ? i + 1 : k;
            int need = ((a[i] - currentValue) / kCurr) + ((a[i] - currentValue) % kCurr == 0 ? 0 : 1);
            ans += need;
            currentValue += need * kCurr;
            open += need;
            close[i - kCurr + 1] += need;
        }

        a[i] -= currentValue;
        currentValue -= open;
        open -= close[i];
    }

    cout << ans << endl;

    return;
}

signed main() {
    fastIO();
    int t = 1;
    for(int tc = 1; tc <= t; tc++) solve(tc);
    return 0;
}