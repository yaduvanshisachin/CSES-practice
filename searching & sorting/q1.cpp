#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    while(n--) {
        int x; cin >> x;
        arr.push_back(x);
    }
    
    // unordered_set<int> st;

    // for (int i = 0; i < n; i++) {
    //     int x;
    //     cin >> x;
    //     st.insert(x);
    // }

    // cout << st.size() << '\n';
    // return 0;

    sort(arr.begin(), arr.end());

    int count = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i-1])
            count++;
    }

    cout << count << "\n";

}