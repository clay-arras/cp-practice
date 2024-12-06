#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long MOD = 1e9+7;
void solve() {
    int N; cin >> N;

    int T = (N+1)*N/2;
    if (T % 2) {
        cout << 0 << endl;
        return;
    }
    T/=2;
    vector<vector<int>> dp(N+10, vector<int>(T+10, 0));

    dp[0][0] = 1;
    for (int i=1; i<=N-1; i++) {
        for (int j=0; j<=T; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-i>=0)
                dp[i][j] += dp[i-1][j-i];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[N-1][T] << endl;
}

// dp[i][j] where i is the first i numbers
// j is the difference between the two sets
// the result is the number of sets that qualify

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

