#include <bits/stdc++.h>
using namespace std;

int maxSize = 10;
int *queueA = new int[maxSize]; 
int head;
int tail;

void intializequeueA() {
    head = 0;
    tail = -1;
}

void push(int x) {
    tail += 1;
    queueA[tail] = x;
}

void pop() {
    head += 1;
}

int front() {
    return queueA[head];
}

bool isEmpty() {
    if(head > tail) return true;
    else return false;
}

int main() {

    return 0;
}