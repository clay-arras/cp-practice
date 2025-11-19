#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

int m, x;

int topDown(int i, int j, vector<vector<int>>& dp, vector<pair<int, int>>& p) {
    if (j - 1 >= 0 && i - x >= 0)
        dp[i][j] = topDown(i-x, j-1, dp, p);
    if (j - 1 >= 0 && i + p[j-1].first - x >= 0)
        dp[i][j] = max(dp[i][j], topDown(i+p[j-1].first-x, j-1, dp, p) + p[j-1].second);
    return dp[i][j];
}

void solve() {
    cin >> m >> x;

    vector<pair<int, int>>p(m);
    for (auto& i : p)
        cin >> i.first >> i.second;

    vector<vector<int>> dp(m*x+1e5, vector<int> (m+1e5, 0));
    cout << topDown(m*x, m, dp, p) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*



*/
