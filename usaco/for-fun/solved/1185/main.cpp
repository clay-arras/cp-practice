#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MOD = 1e9+7;
const int MX = 1e3+2;

void solve() {
    int N; cin >> N;

    vector<int> H(N);
    for (int& i : H)
        cin >> i;

    int mn = *min_element(H.begin(), H.end());
    int ans = 0;
    for (int t=0; t<=(N % 2 ? mn : 0); t++) {
        vector<vector<int>> dp(N, vector<int>(MX, 0));
        for (int j=0; j<=H[0]; j++)
            dp[0][j] = 1;

        for (int i=1; i<N; i++) {
            vector<int> pref(MX, 0);
            for (int j=1; j<MX; j++)
                pref[j] = (pref[j-1] + dp[i-1][j-1]) % MOD;

            for (int y=0; y<=H[i]; y++) 
                dp[i][y] = (dp[i][y] + pref[H[i] - y + 1]) % MOD;
        }

        ans = (ans + dp[N-1][0]) % MOD;
        for (int i=0; i<N; i++)
            H[i]--;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
