#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    bool flag = false;
    
    vector<int> color(n, -1);
    for(int node = 0; node < n; node++) {
        if(color[node] != -1) continue;

        color[node] = 0;
        
        queue<int> q;
        q.push(node);
        ans.push_back(color[node]);

        while(!q.empty()) {
            int curr = q.front(); q.pop();

            for(int ngbr : adj[curr]) {
                if(color[ngbr] == color[curr]) {
                    flag = true;
                    break;
                }

                if(color[ngbr] == -1) {
                    color[ngbr] = 1 - color[curr];
                    ans.push_back(color[ngbr]);
                    q.push(ngbr);
                }
            }

            if(flag) break;
        }

        if(flag) break;
    }

    if(flag) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        cout << color[i] + 1 << " ";
    }
    cout << '\n';

    return 0;
}


// n pupils and m friendship pairs
//if 2 students are freind.. they should not be assigned to the same group