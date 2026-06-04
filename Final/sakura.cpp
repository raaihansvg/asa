#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Nama : Raihan Lazuardi
// NIM  : 24060124140178
// Lab  : B2

int n;
vector<vector<int>> jarak;
int bestCost;
vector<int> bestRute;

void branchAndBound(int posisi, int biayaSekarang, int langkah, vector<bool>& sudahDikunjungi, vector<int>& ruteSekarang) {
    if (langkah == n) {
        int totalBiaya = biayaSekarang + jarak[posisi][0];
        if (totalBiaya < bestCost) {
            bestCost = totalBiaya;
            bestRute = ruteSekarang;
        }
        return;
    }

    for (int tujuan = 1; tujuan < n; tujuan++) {
        if (sudahDikunjungi[tujuan]) continue;
        if (jarak[posisi][tujuan] == 0) continue;

        int biayaBaru = biayaSekarang + jarak[posisi][tujuan];

        // kalo udah lebih mahal dari best skip
        if (biayaBaru >= bestCost) {
            continue;
        }
        sudahDikunjungi[tujuan] = true;
        ruteSekarang.push_back(tujuan);
        branchAndBound(tujuan, biayaBaru, langkah + 1, sudahDikunjungi, ruteSekarang);
        sudahDikunjungi[tujuan] = false;
        ruteSekarang.pop_back();
    }
}

int main() {
    cin >> n;
    jarak.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> jarak[i][j];
    bestCost = INT_MAX;
    vector<bool> sudahDikunjungi(n, false);
    sudahDikunjungi[0] = true;
    vector<int> ruteSekarang = {0};
    branchAndBound(0, 0, 1, sudahDikunjungi, ruteSekarang);

    // print rute
    string namaLokasi = "ABCDEF";
    for (int i = 0; i < (int)bestRute.size(); i++) {
        if (i > 0) cout << " ";
        cout << namaLokasi[bestRute[i]];
    }
    cout << " A" << endl;
    cout << bestCost << endl;

    return 0;
}