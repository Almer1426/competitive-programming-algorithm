#include <bits/stdc++.h>
using namespace std;

// zero based
int sizeArr, maxSize, *arrHeap; // dynamic array 

int n = 8;
int a[] = {1, 31, 21, 20, 2, 34, 100, 5};

void initializeHeap(int n) {
    sizeArr = 0;
    maxSize = n;
    arrHeap = new int[maxSize];

    return;
}

int getParent(int x) {
    return (x - 1) / 2;
}

int getLeft(int x) {
    return 2 * x + 1;
}

int getRight(int x) {
    return 2 * x + 2;
}

void dynamicArray(int x) {
    if(sizeArr == maxSize) {
        int *temp = new int[maxSize * 2];
        for(int i = 0; i < sizeArr; i++) {
            temp[i] = arrHeap[i];
        }

        arrHeap = temp;
        maxSize *= 2;
    }

    return;
}

void push(int x) {
    dynamicArray(x);
    arrHeap[sizeArr] = x;

    int i = sizeArr;
    while((i > 0) && (arrHeap[i] > arrHeap[getParent(i)])) {
        swap(arrHeap[i], arrHeap[getParent(i)]); // swap otomatis (menggunakan fungsi)

        i = getParent(i);
    }
    sizeArr += 1;

    return;
}

void pop() {
    swap(arrHeap[0], arrHeap[sizeArr - 1]);
    sizeArr -= 1;

    int i = 0;
    bool swapped = true;
    while(swapped) {
        int maxIndex = i; // index now

        if((getLeft(i) < sizeArr) && (arrHeap[maxIndex] < arrHeap[getLeft(i)])) {
            maxIndex = getLeft(i);
        }
        if((getRight(i) < sizeArr) && (arrHeap[maxIndex] < arrHeap[getRight(i)])) {
            maxIndex = getRight(i);
        }

        swap(arrHeap[i], arrHeap[maxIndex]);
        swapped = (i == maxIndex)? false : true;
        i = maxIndex;
    }

    return;
}

int top() {
    return arrHeap[0];
}

void heapify(int rootIndex) {
    int i = rootIndex;
    bool swapped = true;
    while(swapped) {
        int maxIndex = i; // index now

        if((getLeft(i) < sizeArr) && (arrHeap[maxIndex] < arrHeap[getLeft(i)])) {
            maxIndex = getLeft(i);
        }
        if((getRight(i) < sizeArr) && (arrHeap[maxIndex] < arrHeap[getRight(i)])) {
            maxIndex = getRight(i);
        }

        swap(arrHeap[i], arrHeap[maxIndex]);
        swapped = (i == maxIndex)? false : true;
        i = maxIndex;
    }

    return;

}

void popHeapify() {
    swap(arrHeap[0], arrHeap[sizeArr - 1]);
    sizeArr -= 1;
    heapify(0);

    return;
}

void makeHeap(int n) {
    initializeHeap(n);

    for(int i = 0; i < n; i++) {
        arrHeap[sizeArr] = a[i];
        sizeArr += 1;
    }

    for(int i = (n / 2) - 1; i >= 0; i--) {
        heapify(i);
    }

    return;
}

void heapSort(int n) {
    makeHeap(n); // ubah array A dengan N banyak data ke bentuk heap;

    for(int i = 0; i < n; i++) {
        a[i] = top();
        popHeapify();
    }

    return;
}

int main() {
    sizeArr = 0;
    maxSize = 1;
    arrHeap = new int[maxSize];

    return 0;
}