#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using namespace std;

/* Nama : Raihan Lazuardi*/
/* Nim  : 24060124140178*/
int main() {
    int n, k;
    cin >> n >> k;

    vector<string> peta(n);
    for (int i = 0; i < n; i++) cin >> peta[i];

  
    vector<int> posisiHunter, posisiDevil;
    for (int i = 0; i < n; i++) {
        if (peta[i] == "P") posisiHunter.push_back(i);
        else if (peta[i] == "T") posisiDevil.push_back(i);
    }

    vector<bool> devilSudahMati(posisiDevil.size(), false);

    int jumlahKalah = 0;

    for (int posH : posisiHunter) {
        int jarakTerdekat = INT_MAX;
        int pilihanDevil  = -1; 

        for (int i = 0; i < (int)posisiDevil.size(); i++) {
            if (devilSudahMati[i]) continue; 

            int jarak = abs(posH - posisiDevil[i]);
            if (jarak <= k && jarak < jarakTerdekat) {
                jarakTerdekat = jarak;
                pilihanDevil  = i;
            }
        }

        if (pilihanDevil != -1) {
            devilSudahMati[pilihanDevil] = true;
            jumlahKalah++;
        }
    }

    cout << jumlahKalah << endl;
    return 0;
}