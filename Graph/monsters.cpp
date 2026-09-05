#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

bool isValid(int i, int j, vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();

    return (i >= 0 && i < m && j >= 0 && j < n)
            && grid[i][j] != '#';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n; cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));

    pii start = {-1, -1};
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 'A')
                start = {i, j};  
        }
    }

    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    char dirChar[4] = {'R', 'L', 'D', 'U'};

    //step 1 : multi-source BFS for all monsters
    // find earliest time a monster can reach to a cell
    
    vector<vector<int>> monster_time(m, vector<int>(n, INT_MAX));
    queue<pii> monster_q;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'M') {
                monster_time[i][j] = 0;
                monster_q.push({i, j});
            }
        }
    }

    while(!monster_q.empty()) {
        auto [x, y] = monster_q.front(); monster_q.pop();

        for(auto &dir : dirs) {
            int nx = x + dir[0]; 
            int ny = y + dir[1]; 

            if(isValid(nx, ny, grid) && 
                    monster_time[x][y] + 1 < monster_time[nx][ny]) {
                
                monster_time[nx][ny] = monster_time[x][y] + 1;
                monster_q.push({nx, ny});
            }
        }
    }

    //step 2 : start BFS from A avoiding monster reach
    vector<vector<int>> dist(m, vector<int>(n, -1));
    vector<vector<char>> parent(m, vector<char>(n, 0));
    // vector<vector<bool>> vis(m, vector<bool>(n, false));
    pii exit = {-1, - 1};

    queue<pii> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        
        //reached to boundry
        if(x == 0 || x == m - 1 || y == 0 || y == n - 1) {
            exit = {x, y};
            break;
        }

        for(int d = 0; d < 4; d++) {
            int nx = x + dirs[d][0];
            int ny = y + dirs[d][1];
            
            if(!isValid(nx, ny, grid)) continue;
            if(dist[nx][ny] != -1) continue; 

            if(dist[x][y] + 1 >= monster_time[nx][ny]) 
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            parent[nx][ny] = dirChar[d];
            q.push({nx, ny});
        }
    }

    //could'nt escape
    if(exit.first == -1) {
        cout << "NO" << endl;
        return 0;
    }

    //reconstruct path
    string path;
    pii curr = exit;

    while(curr != start) {
        char dir = parent[curr.first][curr.second];
        path.push_back(dir);

        // Move backwards.
        if (dir == 'R') {
            // We came here from the left.
            curr.second--;
        }
        else if (dir == 'L') {
            // We came here from the right.
            curr.second++;
        }
        else if (dir == 'D') {
            // We came here from above.
            curr.first--;
        }
        else if (dir == 'U') {
            // We came here from below.
            curr.first++;
        }
    }
    
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';

    return 0;
}