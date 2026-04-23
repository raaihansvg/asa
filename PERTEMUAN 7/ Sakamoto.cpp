#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<tuple>
#include<queue>
using namespace std;
/* NAMA : RAIHAN LAZUARDI */
/* NIM : 24060124140178*/
/* KELAS : B*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int baris, kolom;
    cin >> baris >> kolom;

    vector<vector<char>> petaKota(baris, vector<char>(kolom));
    int startR = -1, startC = -1;

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cin >> petaKota[i][j];
            if (petaKota[i][j] == 'S') {
                startR = i;
                startC = j;
            }
        }
    }

    int deltaR[] = {-1, 1, 0, 0};
    int deltaC[] = {0, 0, -1, 1};

    vector<vector<bool>> sudahDikunjungi(baris, vector<bool>(kolom, false));

    queue<tuple<int, int, int>> antreanLangkah;
    antreanLangkah.push({startR, startC, 0});
    sudahDikunjungi[startR][startC] = true;

    while (!antreanLangkah.empty()) {
        auto [r, c, langkah] = antreanLangkah.front();
        antreanLangkah.pop();

        if (petaKota[r][c] == 'C') {
            cout << langkah << endl;
            return 0;
        }

        for (int arah = 0; arah < 4; arah++) {
            int nr = r + deltaR[arah];
            int nc = c + deltaC[arah];

            bool didalam = (nr >= 0 && nr < baris && nc >= 0 && nc < kolom);
            if (didalam && !sudahDikunjungi[nr][nc] && petaKota[nr][nc] != '#') {
                sudahDikunjungi[nr][nc] = true;
                antreanLangkah.push({nr, nc, langkah + 1});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}