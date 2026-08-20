//Counting number of components in grid

#include <bits/stdc++.h>
using namespace std;

int m, n;
int dirs[4][2]  = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis) {
    
    vis[i][j] = 1;
    
    for(auto & dir : dirs) {
        int x = i + dir[0];
        int y = j + dir[1];
        
        if(x < 0 || x >= m || y < 0 || y >= n) continue;

        if(!vis[x][y] && grid[x][y] == '.') {
            dfs(x, y, grid, vis);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    m, n; 
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for(auto &row : grid) {
        for(int i = 0; i < n; i++) {
            cin >> row[i];
        }
    }
    
    vector<vector<int>> vis(m, vector<int>(n, 0));
    
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] && grid[i][j] == '.') {
                dfs(i, j, grid, vis);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}