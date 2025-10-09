#include <bits/stdc++.h>
using namespace std;

int fpb(int a, int b) {
    if(b == 0) return a;
    else return fpb(b, a % b);
}

int main() {
    int x, y;
    cin >> x >> y;

    int ans = fpb(x, y);
    cout << ans << endl;

    return 0; 
}