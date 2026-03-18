#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


//Nama : Raihan Lazuardi
//NIM  : 24060124140178
//Lab  : B1


using namespace std;

string inputDNA;
vector<string> Hasil;
vector<bool> SudahDipakaiBelum;


bool CekHurufVokal(char huruf){
    return huruf == 'A' || huruf =='I' || huruf == 'U' || huruf == 'E'||
    huruf == 'O' || huruf == 'a' || huruf == 'i' || huruf == 'u' ||
    huruf == 'e' || huruf =='o';
}


void AturanSusunan(string susunan){
    if(susunan.length() == inputDNA.length()){
        Hasil.push_back(susunan);
        return;
    }

    for(int i = 0; i < inputDNA.length(); i++){
        if(SudahDipakaiBelum[i]){
            continue;
        }

        if(!susunan.empty()){
            char hurufTerakhir = susunan.back();
            char hurufBaru = inputDNA[i];

            if(CekHurufVokal(hurufTerakhir)&& CekHurufVokal(hurufBaru)){
                continue;
            }
        }
        SudahDipakaiBelum[i] = true;
        AturanSusunan(susunan + inputDNA[i]);
        SudahDipakaiBelum[i] = false;

    }
}


int main(){
    cin >> inputDNA;

    SudahDipakaiBelum.assign(inputDNA.length(), false);

    AturanSusunan("");

    if (Hasil.empty()){
        cout<<"TIDAK ADA";
    }else{
        for(int i = 0; i < Hasil.size(); i++){
            cout << Hasil[i] << endl;
        }
    }
    return 0;
}


