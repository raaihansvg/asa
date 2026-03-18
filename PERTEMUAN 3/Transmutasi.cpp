#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int jumlah_kristal;
vector<int> daftar_energi;
int target_energi;

// Fungsi rekursif untuk mencoba memasukkan kristal ke 3 lingkaran
bool coba_bagi(int indeks_saat_ini, vector<int>& energi_lingkaran) {
    // Basis: semua kristal sudah diproses
    if (indeks_saat_ini == jumlah_kristal) {
        return (energi_lingkaran[0] == target_energi &&
                energi_lingkaran[1] == target_energi &&
                energi_lingkaran[2] == target_energi);
    }

    int energi_sekarang = daftar_energi[indeks_saat_ini];

    // Coba masukkan ke salah satu dari 3 lingkaran
    for (int i = 0; i < 3; i++) {

        // Pruning: jika melebihi target, tidak perlu lanjut
        if (energi_lingkaran[i] + energi_sekarang > target_energi)
            continue;

        energi_lingkaran[i] += energi_sekarang;

        if (coba_bagi(indeks_saat_ini + 1, energi_lingkaran))
            return true;

        energi_lingkaran[i] -= energi_sekarang; // backtrack

        // Optimasi: jika lingkaran kosong gagal, tidak perlu coba kosong lain
        if (energi_lingkaran[i] == 0)
            break;
    }

    return false;
}

int main() {
    cin >> jumlah_kristal;

    daftar_energi.resize(jumlah_kristal);

    int total_energi = 0;
    for (int i = 0; i < jumlah_kristal; i++) {
        cin >> daftar_energi[i];
        total_energi += daftar_energi[i];
    }

    // Syarat dasar Equivalent Exchange
    if (jumlah_kristal < 3 || total_energi % 3 != 0) {
        cout << "REBOUND";
        return 0;
    }

    target_energi = total_energi / 3;

    // Urutkan dari besar ke kecil supaya pruning lebih cepat
    sort(daftar_energi.rbegin(), daftar_energi.rend());

    // Jika kristal terbesar lebih besar dari target → mustahil
    if (daftar_energi[0] > target_energi) {
        cout << "REBOUND";
        return 0;
    }

    vector<int> energi_lingkaran(3, 0);

    if (coba_bagi(0, energi_lingkaran))
        cout << target_energi;
    else
        cout << "REBOUND";

    return 0;
}