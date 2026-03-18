#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Nama : Raihan Lazuardi
//Nim  : 24060124140178
//Lab  : B2

//Mencari Total Energi Fragmen Komet Tiamat

long long HitungEnergi(vector<int>&SimpanEnergi, int kiri, int kanan){
    if(kiri == kanan){
        return SimpanEnergi[kiri];
    }

    int tengah = (kiri + kanan) / 2;

    long long SimpanValueKiri = HitungEnergi(SimpanEnergi, kiri, tengah);
    long long SimpanValueKanan = HitungEnergi(SimpanEnergi, tengah +1, kanan);

    return SimpanValueKiri + SimpanValueKanan;
}



int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout <<HitungEnergi(arr,0, n-1) << endl;
    return 0;
}