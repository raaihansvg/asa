#include <iostream>
#include <algorithm>
#include <climits>

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long dist[5][5];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    // Edge case: n == 2
    if (n == 2) {
        long long total = dist[0][1] + dist[1][0];
        cout << total << "\n";
        cout << "A B A\n";
        return 0;
    }

    // Nodes selain titik awal (0)
    int nodes[4];
    int size = n - 1;

    for (int i = 0; i < size; ++i) {
        nodes[i] = i + 1;
    }

    long long minDistance = LLONG_MAX;
    int bestRoute[4];

    do {
        long long currentDistance = 0;

        // dari 0 ke node pertama
        currentDistance += dist[0][nodes[0]];

        // antar node
        for (int i = 0; i < size - 1; ++i) {
            currentDistance += dist[nodes[i]][nodes[i + 1]];
        }

        // kembali ke 0
        currentDistance += dist[nodes[size - 1]][0];

        if (currentDistance < minDistance) {
            minDistance = currentDistance;

            for (int i = 0; i < size; ++i) {
                bestRoute[i] = nodes[i];
            }
        }

    } while (next_permutation(nodes, nodes + size));

    cout << minDistance << "\n";

    cout << "A ";
    for (int i = 0; i < size; ++i) {
        cout << char('A' + bestRoute[i]) << " ";
    }
    cout << "A\n";

    return 0;
}


