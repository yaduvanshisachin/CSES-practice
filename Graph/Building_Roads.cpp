#include <bits/stdc++.h>
using namespace std;

#define ll long long

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 0);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    DSU dsu(n);
    
    while(m--) {
        int u, v;  cin >> u >> v;
        dsu.unite(u-1, v-1); // 0 based indexing
    }

    // int components = 0;
    vector<int> parents;
    for(int i = 0; i < n; i++) {
        if(dsu.find(i) == i) {
            // components++;
            parents.push_back(i);
        }
    }

    cout << parents.size() - 1 << endl;
    
    for(int i = 1; i < parents.size(); i++) {
        cout << parents[0] + 1 << " " << parents[i] + 1 << endl;
    }

    return 0;
}