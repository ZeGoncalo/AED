#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int dfs(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (visited[r][c] || grid[r][c] == '.') return 0;
    visited[r][c] = true;
    int size = 1;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            size += dfs(r + dr, c + dc);
        }
    }
    return size;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> R >> C;
        grid = vector<vector<char>>(R, vector<char>(C));
        visited = vector<vector<bool>>(R, vector<bool>(C, false));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> grid[i][j];
        int components = 0;
        int largest = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '#' && !visited[i][j]) {
                    int size = dfs(i, j);
                    components++;
                    if (size > largest) largest = size;
                }
            }
        }
        cout << components << " " << largest << endl;
    }
    return 0;
}
