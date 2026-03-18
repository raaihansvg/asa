#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Nama : Raihan Lazuardi
//Nim  : 24060124140178
//ASA B2
//Striker Terbaik
struct striker {
    int id;
    int skill;
    int ego;
};

striker tentukan_juara(vector<striker> daftar_pemain) {
    if (daftar_pemain.size() == 1) {
        return daftar_pemain[0];
    }

    vector<striker> babak_berikutnya;
    for (int i = 0; i < (int)daftar_pemain.size(); i += 2) {
        striker pemain_1 = daftar_pemain[i];
        striker pemain_2 = daftar_pemain[i + 1];

        int kekuatan_1 = pemain_1.skill + pemain_1.ego;
        int kekuatan_2 = pemain_2.skill + pemain_2.ego;

        striker pemenang;
        if (kekuatan_1 > kekuatan_2) {
            pemenang = pemain_1;
        } else if (kekuatan_2 > kekuatan_1) {
            pemenang = pemain_2;
        } else {
            if (pemain_1.id < pemain_2.id) {
                pemenang = pemain_1;
            } else {
                pemenang = pemain_2;
            }
        }
        pemenang.ego = pemenang.ego + 1;
        babak_berikutnya.push_back(pemenang);
    }
    return tentukan_juara(babak_berikutnya);
}

int main() {
    int jumlah_peserta;
    if (!(cin >> jumlah_peserta)) return 0;
    vector<int> daftar_skill(jumlah_peserta);
    vector<int> daftar_ego(jumlah_peserta);

    for (int i = 0; i < jumlah_peserta; i++){
        cin >> daftar_skill[i];
    }
    for (int i = 0; i < jumlah_peserta; i++){ 
        cin >> daftar_ego[i];
    }

    vector<striker> semua_pemain;
    for (int i = 0; i < jumlah_peserta; i++) {
        striker s;
        s.id = i + 1;
        s.skill = daftar_skill[i];
        s.ego = daftar_ego[i];
        semua_pemain.push_back(s);
    }
    striker sang_juara = tentukan_juara(semua_pemain);

    cout << sang_juara.id << endl;

    return 0;
}