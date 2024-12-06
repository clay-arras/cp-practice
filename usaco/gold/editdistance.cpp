#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 5e3+5;
void solve() {
    string s1, s2; cin >> s1 >> s2;
    int len1 = (int)s1.size();
    int len2 = (int)s2.size();
    vector<vector<int>> dp(len1+1, vector<int> (len2+1, 1e9));

    dp[0][0] = 0;
    for (int i=0; i<=len1; i++) {
        for (int j=0; j<=len2; j++) {
            if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if (i and j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s1[i-1] != s2[j-1]));
        }
    }
    cout << dp[len1][len2] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}
