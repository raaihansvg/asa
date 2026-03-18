#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<long long> A(n1);
    vector<long long> B(n2);

    for(int i = 0; i < n1; i++) {
        cin >> A[i];
    }


    for(int i = 0; i < n2; i++) {
        cin >> B[i];
    }

    vector<long long> hasil;


    for(int i = 0; i < n1; i++) {
        bool ada = false;

        for(int j = 0; j < n2; j++) {
            if(A[i] == B[j]) {
                ada = true;
                break;
            }
        }

        if(!ada) {
            hasil.push_back(A[i]);
        }
    }

    if(hasil.empty()) {
        cout << "KOSONG";
    } else {
        for(long long x : hasil) {
            cout << x << " ";
        }
    }

    return 0;
}
