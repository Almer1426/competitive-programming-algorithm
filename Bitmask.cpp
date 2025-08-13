#include <bits/stdc++.h>
using namespace std;

bool isOdd(int x) {
    return x & 1; 
}

int multiplyBy2(int x) {
    return x << 1;
}

int divideBy2(int x) {
    return x >> 1;
}

bool isPowerOfTwo(int x) {
    return x > 0 && ((x & (x - 1)) == 0);
}

int countSetBits(int x) {
    int cnt = 0;
    while(x != 0) {
        x &= (x - 1); // hapus 1-bit terakhir
        cnt++;
    }

    return cnt;
}

bool isBitSet(int x, int i) {
    return (x & (i << i)) != 0;
}

int findUnique(vector<int> &a) {
    int ans = 0;
    for(auto num : a) ans ^= num;
    return ans;
}

int main() {
    int n = 1;
    cout << bitset<8>(n) << endl;

    string s = "10111";
    bitset<8> variable(s);
    cout << variable.to_ulong() << endl;

    /* 
        operasi & (AND):
        0 & 0 = 0
        1 & 0 = 0
        0 & 1 = 0
        1 & 1 = 1

        operasi | (OR):
        0 | 0 = 0
        1 | 0 = 1
        0 | 1 = 1
        1 | 1 = 1

        operasi ~ (NOT):
        ~1 = 0
        ~0 = 1
        ~0101 = 1010

        operasi ^ (XOR):
        0 ^ 0 = 0
        1 ^ 0 = 1
        0 ^ 1 = 1
        1 ^ 1 = 0

        operasi << (left shift):
        a (0101) << 1 = 1010 (10)

        operasi >> (right shift):
        a (0101) >> 1 = 0010 (2)
    */

    // biner dari 1 adalah 1, ini berguna untuk mengecek bit terakhir dari suatu angka apakah 0 atau 1
    cout << isOdd(1) << endl; // jika bit akhir adalah 1 maka ganjil, jika bit akhir adalah 0 maka genap

    cout << multiplyBy2(4) << endl; // geser 1 bit ke kiri akan menghasilkan operasi kali 2
    cout << divideBy2(8) << endl; // geser 1 bit ke kanan akan menghasilkan operasi bagi 2

    cout << isPowerOfTwo(16) << endl; // sebuah bilangan adalah pangkat dari dua jika dan hanya jika ada satu bit di dalam biner

    cout << countSetBits(10) << endl; // menghitung jumlah bit yang 1

    cout << isBitSet(12, 2) << endl; // isBitSet(x, i) mengecek apakah bit ke-i dalam angka x itu bernilai 1

    int x = 10, i = 2;
    x |= (1 << i); // set on bit ke-i gunakan |
    x &= ~(1 << i); // unset atau set off bit ke-i gunakan & ~
    x ^= (1 << i); // toggle atau flip bit ke-i gunakan ^

    /* 
    XOR untuk menemukan angka yang tidak berpasangan
    a XOR a = 0
    a XOR 0 = a

    maka
    */
    vector<int> a = {2, 3, 3, 2, 4};
    cout << findUnique(a) << endl;

    return 0;
}