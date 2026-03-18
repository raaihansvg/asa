#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;

    int jarak[5][5];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> jarak[i][j];
        }
    }

    if(n == 2){
        int total = jarak[0][1] + jarak[1][0];
        cout << total << "\n";
        cout << "A B A\n";
        return 0;
    }

    int nodes[4];
    int size = n - 1;

    for(int i = 0; i < size; i ++){
        nodes[i] = i + 1;
    }

    long long JarakTerkecil = LLONG_MAX;
    int bestJalan[4];


    do{
        int JalanSekarang = 0;
        JalanSekarang += jarak[0][nodes[0]];

        for(int i = 0; i < size -1; i ++){
            JalanSekarang += jarak[nodes[i]][nodes[i+1]];
        }

        JalanSekarang += jarak[nodes[size-1]][0];

        if (JalanSekarang < JarakTerkecil){
            JarakTerkecil = JalanSekarang;

            for(int i = 0; i < size; i ++){
                bestJalan[i] = nodes[i];
            }
        }
        
    }while(next_permutation(nodes, nodes + size));

    
    cout << JarakTerkecil << "\n";

    cout << "A "; 

    for(int i = 0; i < size; i ++){
        cout << char('A' + bestJalan[i]) << " ";
    }

    cout << "A\n";
    

}
