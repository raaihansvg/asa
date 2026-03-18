#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Nama : Raihan Lazuardi
//Nim  : 24060124140178
//ASA B2
//Windah Barusadar

int cariBocilKematian(vector<int>& arr,int kiri,int kanan,int bocil){
    if (kiri > kanan){
        return -1;
    }

    int tengah = kiri + (kanan - kiri) / 2;

    if(arr[tengah] == bocil){
        return tengah;
    }else if (bocil < arr[tengah]){
        return cariBocilKematian(arr, kiri, tengah - 1, bocil);
    }else{
        return cariBocilKematian(arr, tengah+1 , kanan, bocil);
    }
}


int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int bocil;
    cin >> bocil;

    int hasilBangWindahAbsenn = cariBocilKematian(arr,0,n-1,bocil);
    cout << hasilBangWindahAbsenn << endl;
    return 0;
}