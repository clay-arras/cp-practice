#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve(){
    int n; cin >> n;

    vector<int> b(n+5);
    for (int i=0; i<n; i++){
        cin >> b[i+1];
    }

    // dp = minimum skip points
    // you: two actions: kill 1, or 2
    // friend: two actions: kill 1 or 2, calculate skip point later
    // dp[n][you or friend] = minimum skip points
    vector<vector<int>> dp(n+5, vector<int>(2, INT_MAX-5));

    dp[0][0] = 0;
    for (int i=0; i<=n; i++){
        dp[i+2][1] = min(dp[i+2][1], dp[i][0] + b[i+1] + b[i+2]);
        dp[i+1][1] = min(dp[i+1][1], dp[i][0] + b[i+1]);

        dp[i+2][0] = min(dp[i+2][0], dp[i][1]);
        dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
