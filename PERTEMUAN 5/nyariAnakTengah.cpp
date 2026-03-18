#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// Nama : Raihan Lazuardi
// Nim  : 24060124140178
// ASA B2
// cari anak tengah

double CARIIIIIIIII(vector<int>& daftar_a, vector<int>& daftar_b, int kiri, int kanan) {
    int ukuran_a = daftar_a.size();
    int ukuran_b = daftar_b.size();

    int sekat_a = (kiri + kanan) / 2;
    int sekat_b = (ukuran_a + ukuran_b + 1) / 2 - sekat_a;
    int angka_kiri_maks_a, angka_kanan_min_a;
    if (sekat_a == 0) {
        angka_kiri_maks_a = -1000000000;
    } else {
        angka_kiri_maks_a = daftar_a[sekat_a - 1];
    }

    if (sekat_a == ukuran_a) {
        angka_kanan_min_a = 1000000000;
    } else {
        angka_kanan_min_a = daftar_a[sekat_a];
    }
    int angka_kiri_maks_b, angka_kanan_min_b;
    if (sekat_b == 0) {
        angka_kiri_maks_b = -1000000000;
    } else {
        angka_kiri_maks_b = daftar_b[sekat_b - 1];
    }

    if (sekat_b == ukuran_b) {
        angka_kanan_min_b = 1000000000;
    } else {
        angka_kanan_min_b = daftar_b[sekat_b];
    }
    if (angka_kiri_maks_a <= angka_kanan_min_b && angka_kiri_maks_b <= angka_kanan_min_a) {
        if ((ukuran_a + ukuran_b) % 2 == 1) {
            if (angka_kiri_maks_a > angka_kiri_maks_b) {
                return (double)angka_kiri_maks_a;
            } else {
                return (double)angka_kiri_maks_b;
            }
        } 
        else {
            int maks_kiri, min_kanan;  
            if (angka_kiri_maks_a > angka_kiri_maks_b) {
                maks_kiri = angka_kiri_maks_a;
            }else{
                maks_kiri = angka_kiri_maks_b;
            }
            if(angka_kanan_min_a < angka_kanan_min_b) {
                min_kanan = angka_kanan_min_a;
            }else{
                min_kanan = angka_kanan_min_b;
            }
            return (maks_kiri + min_kanan) / 2.0;
        }
    } 
    else if(angka_kiri_maks_a > angka_kanan_min_b) {
        return CARIIIIIIIII(daftar_a, daftar_b, kiri, sekat_a - 1);
    } 
    else{
        return CARIIIIIIIII(daftar_a, daftar_b, sekat_a + 1, kanan);
    }
}

double cariAnaktengah(vector<int>& daftar_a, vector<int>& daftar_b) {
    if (daftar_a.size() > daftar_b.size()) {
        return cariAnaktengah(daftar_b, daftar_a);
    }
    return CARIIIIIIIII(daftar_a,daftar_b,0,(int)daftar_a.size());
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> daftar_a(n), daftar_b(m);

    for(int i = 0; i < n; i++){
        cin >> daftar_a[i];
    }
    for(int i =0; i< m; i++){
        cin >> daftar_b[i];
    }

    double hasil = cariAnaktengah(daftar_a,daftar_b);

    printf("%.1f\n", hasil);

    return 0;
}