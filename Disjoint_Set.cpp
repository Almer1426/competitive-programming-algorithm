#include <bits/stdc++.h>
using namespace std;

vector<int> par;

void initialize(int n) {
    par.resize(n);

    for(int i = 0; i < n; i++) { // zero based
        par[i] = i;
    }

    return;
}

void join(int a, int b) {
    int repA = findRepresentative(a);
    int repB = findRepresentative(b);
    par[repA] = repB;
}

int findRepresentative(int x) {
    if(par[x] == x) {
        return x;
    } else {
        par[x] = findRepresentative(par[x]);
        return par[x];
    }
}

bool check(int a, int b) {
    return (findRepresentative(a) == findRepresentative(b));
}

int main() {
    int n;
    cin >> n; // banyak data

    initialize(n);

    return 0;
}