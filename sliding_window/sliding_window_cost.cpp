#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve(vector<ll>& arr, int k) {
    multiset<ll> left_st, right_st;
    ll leftSum = 0, rightSum = 0;
 
    // Maintain the correct sizes and ordering
    auto rebalance = [&]() {
 
        while (left_st.size() > right_st.size() + 1) {
            ll x = *left_st.rbegin();
 
            left_st.erase(prev(left_st.end()));
            right_st.insert(x);
 
            leftSum -= x;
            rightSum += x;
        }
 
        while (left_st.size() < right_st.size()) {
            ll x = *right_st.begin();
 
            right_st.erase(right_st.begin());
            left_st.insert(x);
 
            rightSum -= x;
            leftSum += x;
        }
    };
 
    auto add = [&](ll x) {
        if (left_st.empty() || x <= *left_st.rbegin()) {
            left_st.insert(x);
            leftSum += x;
        } else {
            right_st.insert(x);
            rightSum += x;
        }
 
        rebalance();
    };
 
    auto remove = [&](ll x) {
        if (left_st.count(x)) {
            left_st.erase(left_st.find(x));
            leftSum -= x;
        } else {
            right_st.erase(right_st.find(x));
            rightSum -= x;
        }
 
        rebalance();
    };
 
    for (int j = 0; j < arr.size(); j++) {
        add(arr[j]);
 
        if (j >= k - 1) {
            ll median = *left_st.rbegin();
 
            ll windowCost =
                (ll)left_st.size() * median - leftSum;
 
            windowCost +=
                rightSum - (ll)right_st.size() * median;
 
            cout << windowCost << " ";
 
            // Remove outdated element
            remove(arr[j - k + 1]);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
 
    solve(arr, k);
    cout << '\n';
 
    return 0;
}
