#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> energi(n);
    for (int i = 0; i < n; i++)
        cin >> energi[i];

    int target;
    cin >> target;

    int kiri = 0, kanan = n - 1, hasilIndeks = -1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (energi[tengah] == target) {
            hasilIndeks = tengah;
            break;
        } else if (energi[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    if (hasilIndeks != -1)
        cout << "Energi ditemukan di indeks " << hasilIndeks << endl;
    else
        cout << "Energi tidak ditemukan" << endl;

    return 0;
}