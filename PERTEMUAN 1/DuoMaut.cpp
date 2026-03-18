#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int jumlah;
    cin >> jumlah;

    vector<int> angka(jumlah);
    for(int i = 0; i < jumlah; i++) {
        cin >> angka[i];
    }

    int terbesar1 = -9999;
    int indeksTerbesar1 = -1;

    for(int i = 0; i < jumlah; i++) {
        if(angka[i] > terbesar1) {
            terbesar1 = angka[i];
            indeksTerbesar1 = i;
        }
    }

    int terbesar2 = -9999;

    for(int i = 0; i < jumlah; i++) {
        if(i != indeksTerbesar1 && angka[i] > terbesar2) {
            terbesar2 = angka[i];
        }
    }

    cout << terbesar1 + terbesar2 << endl;

    return 0;
}
