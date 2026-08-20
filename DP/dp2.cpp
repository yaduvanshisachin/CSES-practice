//minimizing coins

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

int solve(vector<int> &coins, int target) {
    if(target == 0) return 0;

    int ans = INT_MAX;
    for(auto &coin : coins) {

        if(coin <= target){
            ans = min(ans,  1 + solve(coins, target - coin));
        }
    }

    return ans;
}

int solveTab(vector<int> &coins, int target) {
    //dp[i] = min coins req to make target "tar" 
    vector<int> dp(target + 1, 1e9);
    dp[0] = 0; //target == 0 --> coins needed = 0

    for(int tar = 1; tar <= target; tar++) {

        //transition
        for(auto &coin : coins) {
            if(coin <= tar){
                dp[tar] = min(dp[tar],  1 + dp[tar - coin]);
            }
        }
    }

    return dp[target] == 1e9 ? -1 : dp[target];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target; 
    cin >> n >> target;
    
    vector<int> coins(n);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    cout << solveTab(coins, target) << "\n";

    return 0;
}