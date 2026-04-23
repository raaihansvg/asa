#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//Raihan Lazuardi
//24060124140178
//B2
using namespace std;


int pivot(vector<int> &deret, int rendah, int tinggi) {
    int poros = deret[tinggi];
    int i = rendah - 1;

    for (int j = rendah; j < tinggi; j++) {
        if (deret[j] <= poros) {
            i++;
            swap(deret[i], deret[j]);
        }
    }
    swap(deret[i + 1], deret[tinggi]);
    return i + 1;
}

void QuwikSort(vector<int> &deret, int rendah, int tinggi) {
    if (rendah < tinggi) {
        int indeksTengah = rendah + (tinggi - rendah) / 2;
        swap(deret[indeksTengah], deret[tinggi]);

        int indeksPartisi = pivot(deret, rendah, tinggi);

        QuwikSort(deret, rendah, indeksPartisi - 1);
        QuwikSort(deret, indeksPartisi + 1, tinggi);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int jumlahAngka;
    if (!(cin >> jumlahAngka)) {
        return 0;
    }

    vector<int> daftarAngka(jumlahAngka);
    for (int i = 0; i < jumlahAngka; i++) {
        cin >> daftarAngka[i];
    }

    if (jumlahAngka > 0) {
        QuwikSort(daftarAngka, 0, jumlahAngka - 1);
    }

    for (int i = 0; i < jumlahAngka; i++) {
        cout << daftarAngka[i];
        if (i < jumlahAngka - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}