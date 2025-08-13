#include <stdio.h>

// Kompleksitas O(N + M)
// Max rentang datanya <= 10^7
// Untuk nilai data yang tidak terlalu besar

int main() {
	int n;
	scanf("%d", &n);
	
	int data[1000];
	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	
	// Algoritma Counting Sort
	// Minimal nilai data 0 dan maksimal nilai data 100
	int ftable[101];
	
	// Isi ftable dengan 0
	for(int i = 0; i <= 100; i++) {
		ftable[i] = 0;
	}

	// Mulai Sort
	for(int i = 0; i < n; i++) {
		int x = data[i];
		ftable[x] += ftable[x] + 1;	
	}
	
	int index = 0;
	for(int i = 0; i <= 100; i++) {
		for(int j = 0; j < ftable[i]; j++) {
			data[index] = i;
			index++;
		}
	}
	
	for(int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}	
	
	return 0;
}
