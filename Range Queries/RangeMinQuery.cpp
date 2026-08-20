#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
private:
    vector<ll> tree;
    int n;
    
    //Range-Min segmentTree
    void buidTree(int i, int l, int r, vector<ll> &arr) {
        if(l == r) {
            tree[i] = arr[l];
            return;
        }

        int mid = l + (r - l)/2;

        buidTree(2*i+1, l, mid, arr);
        buidTree(2*i+2, mid + 1, r, arr);

        tree[i] = min(tree[2*i + 1], tree[2*i + 2]);
    }

    ll query(int start, int end, int i, int l, int r) {
        if(l > end || r < start)
            return INT_MAX;

        if(l >= start && r <= end)
            return tree[i];

        int mid = l + (r - l) /2;

        return min(query(start, end, 2*i+1, l, mid), 
                    query(start, end, 2*i+2, mid+1, r) );
    }

public:
    SegmentTree(vector<ll> &arr) {
        n = arr.size();
        tree.assign(4*n, 0);

        buidTree(0, 0, n-1, arr);
    }

    int query(int start, int end) {
        return query(start, end, 0, 0, n-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    SegmentTree t(arr);

    while(q--) {
        int start, end;
        cin >> start >> end;
        start--; end--; //0 based indexing

        cout << t.query(start, end) << "\n";
    }


    return 0;
}