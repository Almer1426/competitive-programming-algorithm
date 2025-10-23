#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int res = arr.front();
  
  	for(int i = 0; i < arr.size(); i++) {
    	int currSum = 0;
        for(int j = i; j < arr.size(); j++) {
        	currSum = currSum + arr[j];
            res = max(res, currSum);
        }
    }
    
    return res;
}

signed main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr);

    return 0;
}