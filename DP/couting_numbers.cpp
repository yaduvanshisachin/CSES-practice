#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[19][11][2][2];

int solve(int pos, int prev, int tight, int started, string s) {
    if(pos == s.length()) return 1;

    if(dp[pos][prev][tight][started] != -1) 
        return dp[pos][prev][tight][started];

    int limit = tight ? s[pos]-'0' : 9; 

    ll ans = 0;
    for(int d = 0; d <= limit; d++) {
        int nstarted = started || (d != 0);
        
        if(!nstarted) {
            ans += solve(pos+1, 10, tight && (d == limit), nstarted, s);
        }
        else {
            if(d == prev) continue;
            ans += solve(pos + 1, d, tight && (d == limit), nstarted, s);
        }
    }

    return dp[pos][prev][tight][started] = ans;
}

long long calc(long long x) {
    if (x < 0) return 0;

    memset(dp, -1, sizeof(dp));

    string s = to_string(x);
    return solve(0, 10, 1, 0, s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b; cin >> a >> b;

    cout << calc(b) - calc(a - 1) << '\n';
    return 0;
}

//to check leading zeros