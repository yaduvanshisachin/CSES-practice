#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using p = pair<ll, int>; // {distance, node}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;

        adj[u].push_back({v, w});
    }

    priority_queue<p, vector<p>, greater<p>> pq;

    vector<ll> dist(n, LLONG_MAX);
    dist[0] = 0;

    pq.push({0, 0});

    while(!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        // outdated entry
        if (wt != dist[node])
            continue;

        for (auto &[ngbr, d] : adj[node]) {
            if (wt + d < dist[ngbr]) {
                dist[ngbr] = wt + d;
                pq.push({dist[ngbr], ngbr});
            }
        }
    }

    for(ll d : dist) {
        cout << d << " ";
    }

    cout << '\n';
}