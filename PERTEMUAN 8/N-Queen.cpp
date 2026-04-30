#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Raihan Lazuardi 
//240060124140178
//B2

int ukuranPapan;
vector<int> kolomRatu;
bool solusiDitemukan = false;

bool posisiAman(int barisSaat, int kolomSaat) {
    for (int barisAtas = 0; barisAtas < barisSaat; barisAtas++) {
        bool samaKolom    = (kolomRatu[barisAtas] == kolomSaat);
        bool samaDiagonal = (abs(kolomRatu[barisAtas] - kolomSaat) == abs(barisAtas - barisSaat));
        if (samaKolom || samaDiagonal) return false;
    }
    return true;
}

void letakkanRatu(int barisSaat) {
    if (solusiDitemukan) return;

    if (barisSaat == ukuranPapan) {
        solusiDitemukan = true;
        return;
    }

    for (int kolom = 0; kolom < ukuranPapan; kolom++) {
        if (posisiAman(barisSaat, kolom)) {
            kolomRatu[barisSaat] = kolom;
            letakkanRatu(barisSaat + 1);
            if (solusiDitemukan) return;
            kolomRatu[barisSaat] = -1; 
        }
    }
}

int main() {
    cin >> ukuranPapan;

    kolomRatu.assign(ukuranPapan, -1);
    letakkanRatu(0);

    if (!solusiDitemukan) {
        cout << "No Solution" << endl;
    } else {
        for (int baris = 0; baris < ukuranPapan; baris++) {
            for (int kolom = 0; kolom < ukuranPapan; kolom++) {
                if (kolom > 0) cout << " ";
                cout << (kolomRatu[baris] == kolom ? "Q" : ".");
            }
            cout << "\n";
        }
    }
    return 0;
}