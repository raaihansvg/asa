#include <iostream>
using namespace std;

int ukuranPapan;
int jumlahSolusi = 0;

bool kolomTerpakai[13];
bool diagonalKiri[25];
bool diagonalKanan[25];

void tempatkanSenjata(int baris) {
    if (baris == ukuranPapan) {
        jumlahSolusi++;
        return;
    }

    for (int kolom = 0; kolom < ukuranPapan; kolom++) {
        bool adaKonflik = kolomTerpakai[kolom]
                       || diagonalKiri[baris - kolom + ukuranPapan]
                       || diagonalKanan[baris + kolom];

        if (adaKonflik) continue;

        kolomTerpakai[kolom] = true;
        diagonalKiri[baris - kolom + ukuranPapan] = true;
        diagonalKanan[baris + kolom] = true;

        tempatkanSenjata(baris + 1);

        kolomTerpakai[kolom] = false;
        diagonalKiri[baris - kolom + ukuranPapan] = false;
        diagonalKanan[baris + kolom] = false;
    }
}

int main() {
    cin >> ukuranPapan;

    tempatkanSenjata(0);

    cout << jumlahSolusi << endl;
    return 0;
}