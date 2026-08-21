#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int MOD = 1e9 + 7;

    int n; cin >> n;

    vector<int> dp(n+1);
    // dp[i] = no. of ways to generate remaining sum 'i' to make

    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(j > i) continue;

            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}