#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &arr, int k) {
    multiset<ll> left_st, right_st;

    int i = 0;

    for(int j = 0; j < arr.size(); j++) {

        // Insert
        if(left_st.empty() || arr[j] <= *left_st.rbegin())
            left_st.insert(arr[j]);
        else
            right_st.insert(arr[j]);

        // Rebalance
        // while(left_st_st.size() > right_st.size() + 1) {
        //     right_st.insert(*left_st_st.rbegin());
        //     left_st_st.erase(prev(left_st_st.end()));
        // }

        // while(left_st_st.size() < right_st.size()) {
        //     left_st_st.insert(*right_st.begin());
        //     right_st.erase(right_st.begin());
        // }

            if(!left_st.empty() && !right_st.empty()) {
                int maxLeft  = *left_st.rbegin();
                int minRight = *right_st.begin();

                if(maxLeft > minRight) {
                    left_st.erase(left_st.find(maxLeft));
                    right_st.erase(right_st.find(minRight));

                    left_st.insert(minRight);
                    right_st.insert(maxLeft);
                }
            }

        if(j - i + 1 == k) {

            // print Lower median
            cout << *left_st.rbegin() << " ";

            // shrink the window
            if(arr[i] <= *left_st.rbegin())
                left_st.erase(left_st.find(arr[i]));
            else
                right_st.erase(right_st.find(arr[i]));

            i++;

            // Rebalance after deletion
            while(left_st.size() > right_st.size() + 1) {
                right_st.insert(*left_st.rbegin());
                left_st.erase(prev(left_st.end()));
            }

            while(left_st.size() < right_st.size()) {
                left_st.insert(*right_st.begin());
                right_st.erase(right_st.begin());
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    solve(arr, k);

    cout << "\n";

    return 0;
}



// multiset<int> s = {5, 2, 8, 2, 1};

// for (int x : s) {
//     cout << x << " ";  //1 2 2 5 8
// }