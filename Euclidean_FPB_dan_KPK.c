#include <stdio.h>
/*
    == FPB dan KPK ==
    contoh:
    2 = 2^1 * 1
    4 = 2^2 * 1
    5 = 5 * 1
    maka, FPB(2,4,5) = 1 dan KPK(2,4,5) = 2^2 * 5 = 20
    
    Terdapat Sifat:
    KPK(a,b) = a * b / FPB(a,b)
    
    Terdapat algoritma yang dapat mencari FPB(a,b) dalam O(log(min(a,b))), yaitu Algoritma Euclid
*/

int euclid(int a, int b) { // Algoritma Euclid
    if(b == 0) {
        return a;
    } else {
        return euclid(b, a % b);
    }
}

int main() {
    int n, b, result;
    scanf("%d%d", &n, &b);
    result = euclid(n, b);
    printf("%d\n", result); // KPK
    return 0; 
}