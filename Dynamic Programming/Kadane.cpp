#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int res = arr.front();
  
    int mxcurr = arr.front();
    for(auto x : arr) {
        mxcurr = max(mxcurr + x, x);
        res = max(res, mxcurr);
    }
    
    return res;
}

signed main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr);

    return 0;
}