// Merge Sort
#include <iostream>
#include <vector>
using namespace std;

int arr[100] = {10, 9, 2, 3, 4, 3, 10, 7, 5, 6, 3, 4, 1};

void merge(int aLeft, int aRight, int bLeft, int bRight) {
    vector<int> temp;
    int aIndex = aLeft;
    int bIndex = bLeft;

    while((aIndex <= aRight) && (bIndex <= bRight)) {
        if(arr[aIndex] < arr[bIndex]) {
            temp.push_back(arr[aIndex]);
            aIndex++;
        } else {
            temp.push_back(arr[bIndex]);
            bIndex++;
        }
    }

    while(aIndex <= aRight) {
        temp.push_back(arr[aIndex]);
        aIndex++;
    }

    while(bIndex <= bRight) {
        temp.push_back(arr[bIndex]);
        bIndex++;
    }

    int tIndex = 0;
    for(int i = aLeft; i <= bRight; i++) {
        arr[i] = temp[tIndex];
        tIndex++;
    }

    return;
}

void mergeSort(int left, int right) {
    if(left == right) return;
    else {
        int mid = (left + right) / 2;
        
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, mid + 1, right);
    }

    return;
}

int main() {
    mergeSort(0, 12);

    for(int i = 0; i < 13; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}