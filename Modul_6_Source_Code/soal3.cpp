#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int baris, kolom;
    cin >> baris >> kolom;

    vector<vector<int>> grid(baris, vector<int>(kolom));
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            cin >> grid[i][j];

    int SR, SC, FR, FC;
    cin >> SR >> SC >> FR >> FC;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    vector<vector<int>> jarak(baris, vector<int>(kolom, -1));
    queue<pair<int,int>> q;

    jarak[SR][SC] = 0;
    q.push({SR, SC});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == FR && c == FC) {
            cout << jarak[r][c] << endl;
            return 0;
        }

        for (int arah = 0; arah < 4; arah++) {
            int nr = r + dr[arah];
            int nc = c + dc[arah];

            if (nr >= 0 && nr < baris && nc >= 0 && nc < kolom 
                && grid[nr][nc] == 0 && jarak[nr][nc] == -1) {
                jarak[nr][nc] = jarak[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}