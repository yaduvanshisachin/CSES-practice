// Removing Digits

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    //State Defn : dp[i] = min steps to make i to 0
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0; //base case

    for (int i = 1; i <= n; i++) {
        string num = to_string(i);

        for(auto &ch : num) {
            int digit = ch - '0';
            
            if(digit != 0){
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }

    cout << dp[n] << endl;
}