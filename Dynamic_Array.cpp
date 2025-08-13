#include <bits/stdc++.h>
using namespace std;

// Dynamic Array versi C++

int *A;
int currSize = 0;
int maxSize = 1;

void initializedDynamicArray(){
    A = new int[maxSize]();
    return;
}

void push(int x) {
    if(currSize == maxSize) {
        int *tempA = new int[2 * maxSize];
        for(int i = 0; i < maxSize; i++) tempA[i] = A[i];

        delete[] A;

        A = tempA;
        maxSize *= 2;
    }
    
    A[currSize] = x;
    currSize += 1;

    return;
}

int main() {
    initializedDynamicArray();
    push(2);
    push(3);
    push(4);

    for(int i = 0; i < currSize; i++) cout << A[i] << " ";

    return 0;
}