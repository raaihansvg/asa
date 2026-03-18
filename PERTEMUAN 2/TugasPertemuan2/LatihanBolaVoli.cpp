#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tenaga(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tenaga[i][j];
        }
    }

    vector<int> urutan_pemain(n);
    for (int i = 0; i < n; i++) {
        urutan_pemain[i] = i;
    }

    long long damage_maksimal = 0;

  
    do {
        long long total_sekarang = 0;
        for (int posisi = 0; posisi < n; posisi++) {
            int pemain_ke = urutan_pemain[posisi];
            total_sekarang += tenaga[pemain_ke][posisi];
        }

        if (total_sekarang > damage_maksimal) {
            damage_maksimal = total_sekarang;
        }
    } while (next_permutation(urutan_pemain.begin(), urutan_pemain.end()));

    cout << damage_maksimal << endl;

    return 0;
}