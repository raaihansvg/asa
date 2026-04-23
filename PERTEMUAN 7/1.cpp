#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<char, vector<char>> petaLorong;
map<char, bool>         sudahDikunjungi;
vector<char>            urutanKunjungan;

void algoritmaaDFS(char ruanganSekarang) {
    sudahDikunjungi[ruanganSekarang] = true;
    urutanKunjungan.push_back(ruanganSekarang);

    // Tetangga sudah terurut abjad, langsung iterasi
    for (char tetangga : petaLorong[ruanganSekarang]) {
        if (!sudahDikunjungi[tetangga]) {
            algoritmaaDFS(tetangga);
        }
    }
    // Jalan buntu → rekursi selesai → otomatis backtrack ke caller
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int jumlahRuangan, jumlahLorong;
    cin >> jumlahRuangan >> jumlahLorong;

    char ruanganAwal;
    cin >> ruanganAwal;

    for (int i = 0; i < jumlahLorong; i++) {
        char dari, ke;
        cin >> dari >> ke;
        petaLorong[dari].push_back(ke);
    }

    // Sort tetangga tiap ruangan secara abjad A→Z
    for (auto& [ruangan, listTetangga] : petaLorong) {
        sort(listTetangga.begin(), listTetangga.end());
    }

    algoritmaaDFS(ruanganAwal);

    for (int i = 0; i < (int)urutanKunjungan.size(); i++) {
        if (i > 0) cout << ' ';
        cout << urutanKunjungan[i];
    }
    cout << endl;
    return 0;
}