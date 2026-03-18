#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Nama : Raihan Lazuardi
//Nim  : 24060124140178
//Lab  : B2

//Mencari Titan Terkuat


long long CariTitanDulu(vector<int>&TitanJelek, int kiri, int kanan){
    if(kiri == kanan){
        return TitanJelek[kiri];
    }

    int tengah = (kiri + kanan) / 2;

    long long CariTitanDariKiri= CariTitanDulu(TitanJelek, kiri, tengah);
    long long CariTitanDariKanan = CariTitanDulu(TitanJelek, tengah + 1, kanan);

    return max(CariTitanDariKiri, CariTitanDariKanan);
}


int main(){
    int n;
    cin >> n;

    vector<int> TitanPalingKuat(n);

    for(int i = 0; i < n; i +=1){
        cin >> TitanPalingKuat[i];
    }

    cout << CariTitanDulu(TitanPalingKuat, 0, n-1) << endl;
    return 0;
}
