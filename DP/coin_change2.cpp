#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int mod = 1e9 + 7;

    int coin_chage2(vector<int> &arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1));
        
        // base cases
        for(int i=0; i<n; i++)  // sum = 0 ==> 1
            dp[i][0] = 1;
            
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int sum=1; sum <= target ; sum++){
                
                int take = 0;
                if(arr[idx] <= sum){
                    take = dp[idx][sum- arr[idx]];
                }
                
                int skip = dp[idx+1][sum];
                
                dp[idx][sum] = (take + skip) % mod;
            }
        }
        return dp[0][target];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target; cin >> n >> target;

    vector<int> coin(n);
    for(int i = 0; i < n; i++) cin >> coin[i];

    Solution sol;

    cout << sol.coin_chage2(coin, target) << "\n";

    return 0;
}