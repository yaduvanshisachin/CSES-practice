//Coins combination 1

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int solveTab(vector<int> &coins, int target) {
    //dp[i] = number of ways to form target "tar" 
    vector<int> dp(target + 1, 0);
    dp[0] = 1; 

    for(int tar = 1; tar <= target; tar++) {

        //transition
        for(int coin : coins) {
            if(coin <= tar){
                dp[tar] = (dp[tar] + dp[tar - coin]) % mod;
            }
        }
    }

    return dp[target];
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