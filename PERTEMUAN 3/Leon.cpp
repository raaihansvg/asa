#include <iostream>
#include <vector>

using namespace std;

string input_dna;
vector<string> daftar_hasil;
vector<bool> sudah_dipakai;

// Mengecek apakah huruf termasuk vokal
bool adalah_vokal(char huruf) {
    return huruf == 'A' || huruf == 'I' || huruf == 'U' ||
           huruf == 'E' || huruf == 'O';
}

// Backtracking untuk membangun permutasi
void bangun_permutasi(string susunan_sementara) {
    // Basis: jika panjang sudah penuh
    if (susunan_sementara.length() == input_dna.length()) {
        daftar_hasil.push_back(susunan_sementara);
        return;
    }

    for (int indeks_saat_ini = 0; indeks_saat_ini < input_dna.length(); indeks_saat_ini++) {

        if (sudah_dipakai[indeks_saat_ini])
            continue;

        // Cek aturan dua vokal berturut-turut
        if (!susunan_sementara.empty()) {
            char huruf_terakhir = susunan_sementara.back();
            char huruf_baru = input_dna[indeks_saat_ini];

            if (adalah_vokal(huruf_terakhir) && adalah_vokal(huruf_baru))
                continue; // pruning
        }

        sudah_dipakai[indeks_saat_ini] = true;
        bangun_permutasi(susunan_sementara + input_dna[indeks_saat_ini]);
        sudah_dipakai[indeks_saat_ini] = false; // backtrack
    }
}

int main() {
    cin >> input_dna;

    sudah_dipakai.assign(input_dna.length(), false);

    bangun_permutasi("");

    if (daftar_hasil.empty()) {
        cout << "TIDAK ADA";
    } else {
        for (const string &hasil_akhir : daftar_hasil) {
            cout << hasil_akhir << endl;
        }
    }

    return 0;
}