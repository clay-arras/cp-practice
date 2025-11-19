#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MOD = 1e9+7;
void solve() {
    int N; cin >> N;

    vector<string> g(N);
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i=0; i<N; i++)
        cin >> g[i];

    dp[0][0] = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (g[i][j] == '*')
                dp[i][j] = 0;
            else {
                if (i) dp[i][j] += dp[i-1][j];
                if (j) dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[N-1][N-1] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}
