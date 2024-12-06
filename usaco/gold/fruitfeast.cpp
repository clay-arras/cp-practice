#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 5e6+5;
bool dp[2][MX];

void solve() {
    int T, A, B; cin >> T >> A >> B;

    dp[0][0] = true;
    for (int i=0; i<=T; i++) {
        if (i-A>=0) dp[0][i] |= dp[0][i-A];
        if (i-B>=0) dp[0][i] |= dp[0][i-B];
        dp[1][i/2] |= dp[0][i];
    }
    for (int i=0; i<=T; i++) {
        if (i-A>=0) dp[1][i] |= dp[1][i-A];
        if (i-B>=0) dp[1][i] |= dp[1][i-B];
    }
    int ans = -1;
    for (int i=T; i>=0; i--)
        if (dp[1][i])
            ans = max(ans, i);

    cout << ans << endl;
}
// Formula: (a_amount*A + b_amount*B)/2 + a_amount*A + b_amount*B
//
// dp[f][w]
// Keep an ans variable and set it if the f < T
// maxFruits = 2*T/min(A, B);
//
// base case:
// dp[0][0] = 0
// dp[A][0] = A
//
// dp[i][w] = f
// We use I to keep track of when to use the water...
// Variables: fullness, when we use the water
//
// What if we iterate through
// dp[w] and half all of it
// Then add T - dp[w]/2
//
// dp[a][b][w]
// Base case:
// dp[0][0][0] = 0;
//
// Variables: amount of A, amount of B, when we use the water

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

