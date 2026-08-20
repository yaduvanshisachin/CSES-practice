//CSES - Static Range Sum Queries

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// O(log n)
vector<ll> tree;
void buildTree(int i, int l, int r, vector<ll> &arr) {
    if(l == r) {
        tree[i] = arr[l];
        return;
    }

    int mid = l + (r - l)/2;

    buildTree(2*i + 1, l, mid, arr);
    buildTree(2*i + 2, mid + 1, r, arr);

    tree[i] = tree[2*i + 1] + tree[2*i + 2];
}

//query - O(log n)
ll query(int start, int end, int i, int l, int r) {
    if(r < start || l > end)
        return 0;
    
    if(start <= l && r <= end) 
        return tree[i];
    
    int mid = l + (r - l)/2;

    return query(start, end, 2*i + 1, l, mid) +
            query(start, end, 2*i + 2, mid+1, r);
}   

vector<ll> solve(vector<ll> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    
    tree.resize(4 * n);
    buildTree(0, 0, n -1 , arr);

    vector<ll> result;
    for (auto &q : queries) {
        int start = q[0] - 1, end = q[1] - 1;

        result.push_back(query(start, end, 0, 0, n - 1));
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    vector<ll> prefixSum(n + 1, 0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        prefixSum[i + 1] = prefixSum[i] + arr[i];;
    }

    // vector<vector<int>> queries(q, vector<int>(2));
    // for(int i = 0; i < q; i++) 
    //     cin >> queries[i][0] >> queries[i][1];

    while(q--) {
        int start, end;
        cin >> start >> end;

        start--; end--;

        cout << prefixSum[end + 1] - prefixSum[start] << '\n';
    }

    // for(ll x : solve(arr, queries)) {
    //     cout << x << endl;
    // }

    return 0;
}

/* Analysis
    Overall TC - O(q * log n)
    SC - O(n)
*/