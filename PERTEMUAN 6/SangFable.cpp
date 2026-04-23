#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//Raihan Lazuardi
//24060124140178
//B2

int pivot(vector<int> &deret, int rendah, int tinggi) {
    int poros = deret[tinggi];
    int i = rendah;

    for (int j = rendah; j < tinggi; j++) {
        if (deret[j] <= poros) {
            swap(deret[i], deret[j]);
            i++;
        }
    }
    swap(deret[i], deret[tinggi]);
    return i;
}

int QuwikSelek(vector<int> &deret, int rendah, int tinggi, int k) {
    if (rendah <= tinggi) {
        int indeksTengah = rendah + (tinggi - rendah) / 2;
        swap(deret[indeksTengah], deret[tinggi]);

        int indekspivot = pivot(deret, rendah, tinggi);
        if (indekspivot == k) {
            return deret[indekspivot];
        }
        else if (indekspivot > k) {
            return QuwikSelek(deret, rendah, indekspivot - 1, k);
        }
        else {
            return QuwikSelek(deret, indekspivot + 1, tinggi, k);
        }
    }
    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int jumlahAngka, targetK;
    if (!(cin >> jumlahAngka >> targetK)) {
        return 0;
    }r

    vector<int> daftarAngka(jumlahAngka);
    for (int i = 0; i < jumlahAngka; i++) {
        cin >> daftarAngka[i];
    }
    int hasil = QuwikSelek(daftarAngka, 0, jumlahAngka - 1, targetK - 1);

    cout << hasil << endl;

    return 0;
}