#include <iostream>
using namespace std;

int baris, kolom;
int grid[10][10];
bool visited[10][10];
int jumlahJalur = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int fr, int fc) {

    if (r == fr && c == fc) {
        jumlahJalur++;
        return;
    }

    for (int arah = 0; arah < 4; arah++) {
        int nr = r + dr[arah];
        int nc = c + dc[arah];

        if (nr >= 0 && nr < baris && nc >= 0 && nc < kolom 
            && grid[nr][nc] == 0 && !visited[nr][nc]) {
            
            visited[nr][nc] = true;   
            dfs(nr, nc, fr, fc);      
            visited[nr][nc] = false;  
        }
    }
}

int main() {
    int sr, sc, fr, fc;
    
    cin >> baris >> kolom;
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            cin >> grid[i][j];
    
    cin >> sr >> sc >> fr >> fc;

    visited[sr][sc] = true;  
    dfs(sr, sc, fr, fc);
    
    cout << jumlahJalur << endl;
    return 0;
}