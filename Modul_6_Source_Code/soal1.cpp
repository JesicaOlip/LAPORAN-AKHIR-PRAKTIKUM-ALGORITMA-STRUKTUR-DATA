#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V;
    cin >> V;

    vector<char> vertex(V);
    for (int i = 0; i < V; i++) {
        cin >> vertex[i];
    }

    vector<vector<int>> matrix(V, vector<int>(V, 0));

    int E;
    cin >> E;

    for (int i = 0; i < E; i++) {
        char asal, tujuan;
        int W;
        cin >> asal >> tujuan >> W;

        int baris = -1, kolom = -1;
        for (int j = 0; j < V; j++) {
            if (vertex[j] == asal) baris = j;
            if (vertex[j] == tujuan) kolom = j;
        }

        matrix[baris][kolom] = W;
    }

    cout << "Adjacency Matrix:" << endl;

    cout << "  ";
    for (int i = 0; i < V; i++) {
        cout << " " << vertex[i];
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << vertex[i];
        for (int j = 0; j < V; j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}