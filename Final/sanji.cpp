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
int main() {
    int n;
    cin >> n;
    
    vector<int> waktuMulai(n), waktuSelesai(n), keuntungan(n);
    for (int i = 0; i < n; i ++){
        cin >> waktuMulai[i] >> waktuSelesai[i] >> keuntungan[i];
    }

    // urutin based on waktu selesai
    vector<int> urutan(n);
    iota(urutan.begin(), urutan.end(),0);
    sort(urutan.begin(), urutan.end(), [&](int a, int b){
        return waktuSelesai[a] < waktuSelesai[b];
    });

    vector<int> s(n),f(n),v(n);
    for (int i = 0; i < n; i ++){
        s[i] = waktuMulai[urutan[i]];
        f[i] = waktuSelesai[urutan[i]];
        v[i] = keuntungan[urutan[i]];
    }
    // cari last pesanan yg tidak bentrok dengan pesenan ke i
    auto cariPesanan = [&](int i) -> int{
        int lo = 0, hi = i - 1, hasil = -1;
        while(lo <= hi){
            int tengah = (lo + hi) / 2;
            if (f[tengah] <= s[i]){
                hasil = tengah;
                lo = tengah + 1;
            }else{
                hi = tengah -1;
            }
        }
        return hasil;
    };
    // keuntungan max
    vector<long long> dp(n);
    dp[0] = v[0];
    for (int i = 1; i < n; i++) {
        long long ambil = v[i];
        int j = cariPesanan(i);
        if (j >= 0) {
            ambil += dp[j];
        }
        long long skip = dp[i - 1];
        dp[i] = max(ambil, skip);
    }

    cout << dp[n - 1] << endl;
    return 0;
}
