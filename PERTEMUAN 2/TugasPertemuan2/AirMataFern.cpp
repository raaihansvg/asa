#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> daftar_energi(n);
    for (int i = 0; i < n; i++) {
        cin >> daftar_energi[i];
    }

    bool fern_menangis = false;

    // Kita butuh minimal 3 data untuk terjadi 2 kali penurunan berturut-turut
    if (n >= 3) {
        for (int i = 0; i < n - 2; i++) {
            // Cek kondisi: energi[i] > energi[i+1] > energi[i+2]
            if (daftar_energi[i] > daftar_energi[i+1] && daftar_energi[i+1] > daftar_energi[i+2]) {
                fern_menangis = true;
                break;
            }
        }
    }

    if (fern_menangis) {
        cout << "Fern menangis" << endl;
    } else {
        cout << "Fern tersenyum" << endl;
    }

    return 0;
}