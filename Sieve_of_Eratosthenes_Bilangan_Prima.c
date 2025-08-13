#include <stdio.h>
#include <stdbool.h>

long primeList[77777];

void sieveOfEratosthenes(int n) {
    bool eliminated[77777];
    long status = 0;
    for(int i = 2; i <= n; i++) {
        if(!eliminated[i]) {
            primeList[status] = i;
            for(int j = i * i; j <= n; j += i) {
                eliminated[j] = true;
            }
            status++;
        }
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    sieveOfEratosthenes(n);
    for(int i = 0; i >= 0; i++) {
        if(primeList[i] == 0) break;
        printf("%d ", primeList[i]);
    }
    return 0;
}