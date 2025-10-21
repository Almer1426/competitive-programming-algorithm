#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

vector<int> spf(MAXN + 1, 1);

void sieve() {
    spf[0] = 0;
    for(int i = 2; i <= MAXN; i++) {
        if(spf[i] == 1) {
            for(int j = i; j <= MAXN; j += i) {
                if(spf[j] == 1) spf[j] = i;
            }
        }
    }

    return;
}

vector<int> query(int x) {
    vector<int> pf;
    while(x != 1) {
        int p = spf[x];
        pf.push_back(p);
        while(x % p == 0) x /= p;
    }

    return pf;
}

signed main() {
    sieve();

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;
        
        vector<int> primeDivisor = query(x);
        for(auto y : primeDivisor) cout << y << " ";
        cout << endl;
    }

    return 0;
}