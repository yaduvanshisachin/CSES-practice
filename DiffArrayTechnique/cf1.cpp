// C. Little Girl and Maximum Sum - https://codeforces.com/contest/276/problem/C
// https://youtu.be/scH22iKCusU?si=ee4LuPI5mm3Tc-qQ

#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &arr, vector<vector<int>>& queries) {
    int n = arr.size(), q = queries.size();

    // different Array technique
    vector<int> diff(n, 0); 

    for(auto &q : queries) {
        diff[q[0]]++;

        if(q[1] + 1 < n)
            diff[q[1] + 1]--;
    }

    for(int i = 1; i < n; i++)
        diff[i] += diff[i-1];

    sort(diff.begin(), diff.end(), greater<int>());
    sort(arr.begin(), arr.end(), greater<int>());

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += 1LL * arr[i] * diff[i];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> queries(q, vector<int>(2));
    for(int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][0]--;
        queries[i][1]--;
    }
    
    cout << solve(arr, queries) << endl;

    return 0;
}
