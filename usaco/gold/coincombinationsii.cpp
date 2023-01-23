#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif
// SAME THING... ONE WORKS THE OTHER THELSSJKSKJSLKDJFLKSJDFLKJSDKLFJDLSKJ

// NUMBER OF WAYS
//   sum  1  2  3  4  5  6  7  8  9
// l = 1  0  1  0  2  0  3  0  4  0
// l = 2  0  1  1  2  1  0  0  0  0
// l = 3  0  1  1  0  0  0  0  0  0

// DP[current sum][greatest value] = ways to sum

const int mod = 1e9+7;
void solve(){
    int n, x; cin >> n >> x;
    vector<int> c;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        c.push_back(t);
    }
    vector<vector<int>> dp(n+1, vector<int> (x+1, 0));

    dp[0][0] = 1;
    for (int k=1; k<=n; k++){
        for (int s=0; s<=x; s++){
            dp[k][s] = dp[k-1][s];
            if (s-c[k-1] >= 0)
                dp[k][s] += dp[k][s-c[k-1]];

            dp[k][s] %= mod;
        }
    }
    cout << dp[n][x] << endl;
}
/* void solve(){ */
/*     int n, x; cin >> n >> x; */
/*     vector<int> c; */

/*     for (int i=0; i<n; i++){ */
/*         int t; cin >> t; */
/*         c.push_back(t); */
/*     } */
/*     vector<vector<int>> dp(x+1, vector<int> (n+1, 0)); */

/*     dp[0][0] = 1; */
/*     for (int k=1; k<=n; k++){ */
/*         for (int s=0; s<=x; s++){ */
/*             dp[s][k] = dp[s][k-1]; */
/*             if (s-c[k-1] >= 0) */
/*                 dp[s][k] += dp[s-c[k-1]][k]; */

/*             dp[s][k] %= mod; */
/*         } */
/*     } */
/*     cout << dp[x][n] << endl; */
/* } */

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}

