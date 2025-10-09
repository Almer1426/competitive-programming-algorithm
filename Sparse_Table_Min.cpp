#include <bits/stdc++.h>
using namespace std;

int main() {
    // one based
    vector<int> a({1, 3, 3, 1, 2, 6});
    int n = a.size();

    vector<int> lg(n + 1, 0);
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    vector<vector<int>> st(25 + 1, vector<int>(n)); for(int i = 0; i < n; i++) st[0][i] = a[i];
    for(int i = 1; i <= 25; i++) for(int j = 0; j + (1 << i) <= n; j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    auto query = [&](int l, int r) {
        int i = lg[r - l + 1];
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    };

    cout << ">> ";
    cout << query(3 - 1, 4 - 1) << endl;

    return 0;
}