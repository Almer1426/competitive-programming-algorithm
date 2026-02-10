#include <bits/stdc++.h>
using namespace std;

int fpb(int a, int b) {
    if(b == 0) return a;
    else return fpb(b, a % b);
}

int kpk(int a, int b) {
    return a * (b / fpb(a, b));
}

int main() {
    int x, y;
    cin >> x >> y;

    cout << fpb(x, y) << " " << kpk(x, y) << endl;

    return 0; 
}