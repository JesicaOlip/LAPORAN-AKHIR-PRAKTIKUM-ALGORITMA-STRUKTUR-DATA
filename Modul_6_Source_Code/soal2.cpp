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
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Adjacency List:" << endl;

    for (int i = 0; i < V; i++) {
        cout << vertex[i] << " -> ";

        bool adaEdge = false;
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] > 0) {
                if (adaEdge) cout << ", ";
                cout << "(" << vertex[j] << "," << matrix[i][j] << ")";
                adaEdge = true;
            }
        }

        if (!adaEdge) cout << "-";
        cout << endl;
    }

    return 0;
}