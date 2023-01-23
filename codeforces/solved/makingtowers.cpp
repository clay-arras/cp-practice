#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

// store the colors like this
// by color, then by index
// for ex, color[1]
// 0, 3, 6
/* 1 2 3 1 2 3 1 */
const int MX = 1e5+5;
int dp[2][MX];

void solve(){
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        dp[0][i] = 0;
        dp[1][i] = 0;
    }

    for (int r=1; r<=n; r++){
        int x; cin >> x;
        dp[r&1][x] = max(dp[r&1][x], dp[(r^1)&1][x] + 1);
    }

    for (int i=1; i<=n; i++)
        cout << max(dp[0][i], dp[1][i]) << " \n"[i == n];

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
