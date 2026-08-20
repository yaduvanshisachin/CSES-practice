#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<int> adj[n+1];

    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    
    vector<bool> vis(n+1, false);
    vis[1] = true;
        
    vector<int> parent(n+1, -1);
    
    bool found = false;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        
        for(int &v : adj[node]) {
            if(vis[v]) continue;
            
            vis[v] = true;
            parent[v] = node;
            q.push(v);

            if(v == n) {
               found = true; 
               break;
            }
        }
        if(found) break;
    }

    if(!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    

    // Reconstruct path from n back to 1
    vector<int> path;

    int cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for(int node : path) cout << node << " ";
    cout << "\n";

    return 0;
}


// Importent cheej hai -- path ko track krna
// we track path using parent array  -- mujhhe stack ka intution aa rha tha
// parent[] = [x  x  x  x  x  x]
//    idx-        1  2  3  4  5

// ham 5 pe kaha se pahuche the.. parent[5] let say 4 ..push to stack
// ab 4 pe kaha se pahuche the ?  parent[4] let say 1 ...push to stack

// at the end print stack