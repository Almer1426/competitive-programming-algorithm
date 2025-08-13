#include <bits/stdc++.h>
using namespace std;

int topOfStack;
int maxSize = 10;
int *stackA = new int[maxSize]; 

void intializequeueA() {
    topOfStack = 0;
}

void push(int x) {
    topOfStack += 1;
    stackA[topOfStack] = x;
}

void pop() {
    topOfStack -= 1;
}

int top() {
    return stackA[topOfStack];
}

bool isEmpty() {
    if(topOfStack == 0) return true;
    else return false;
}

int main() {

    return 0;
}