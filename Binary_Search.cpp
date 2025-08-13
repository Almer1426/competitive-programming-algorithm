#include <bits/stdc++.h>
using namespace std;

int a[10] = {1, 3, 5, 7, 9, 10, 11, 13, 17, 20}; 

int equal(int x) {
    int kiri = 0;
    int kanan = 9;
    int hasil = -1;

    while(kiri <= kanan && hasil == -1) {
        int tengah = (kanan + kiri) / 2;

        if(x < a[tengah]) {
            kanan = tengah - 1;
        }
        else if(x > a[tengah]) {
            kiri = tengah + 1;
        }
        else if(x == a[tengah]){
            hasil = tengah; // elemen ditemukan di indeks ini
            break;
        }
    }

    return hasil;
}

int lub(int x) {
    int kiri = 0;
    int kanan = 9;
    int hasil = -1;

    while(kiri <= kanan) {
        int tengah = (kanan + kiri) / 2;

        if(x <= a[tengah]) {
            hasil = tengah;
            kanan = tengah - 1;
        }
        else if(x > a[tengah]) {
            kiri = tengah + 1;
        }
    }

    return hasil;
}

int glb(int x) {
    int kiri = 0;
    int kanan = 9;
    int hasil = -1;

    while(kiri <= kanan) {
        int tengah = (kanan + kiri) / 2;

        if(x < a[tengah]) {
            kanan = tengah - 1;
        }
        else if(x >= a[tengah]) {
            hasil = tengah;
            kiri = tengah + 1;
        }
    }

    return hasil;
}

int main() {
    // Binary Search
    int x = 12; // yang dicari
    int kiri = 0; // batas bawah
    int kanan = 9; // batas atas
    int hasil = -1; // hasil pencarian, -1 berarti belum ditemukan
    
    string s;
    cin >> s;

    if(s == "equal") hasil = equal(x);
    else if(s == "glb") hasil = glb(x); // greatest lower bound (batas bawah terbesar)
    else if(s == "lub") hasil = lub(x); // least upper bound (batas atas terkecil)


    if(hasil == -1) cout << "hasil pencarian tidak ada" << endl;
    else cout << a[hasil] << " ada di urutan ke-" << hasil + 1 << endl; // indeks mulai dari 0, jadi tambahkan 1 untuk output

    return 0;
}
