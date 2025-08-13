#include <stdio.h>

void preComputeCombination(int n) {
	int c[n + 1][n + 1];
	
/*
	c[i][0] dan c[i][i] = 1, karena, misal, C n=4 k=0 sama dengan C n=4 k=4 yang hasilnya adalah 1.
*/
	
	for(int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for(int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
		c[i][i] = 1;
	}
	
	// output
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	
	return;
}

int main() {
	int n = 100;
	
	preComputeCombination(n);
	
	return 0;
}
