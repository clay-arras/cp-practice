#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");
    string s;
    cin >> s;

    int n = s.size();
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(6, {0, 0}));
    // dp[i][j] = maximum number of occurrences with the minimum number of cost
    // if we only look at the first i letters and we are on the jth character of "bessie"
    // {occurrences, -cost}

    for (int i = 0; i <= n; i++) {
        dp[i][0] = {0, 0};
    }

    for (int j = 0; j < 5; j++) {
        dp[0][j+1] = {0, 0};
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            if (s[i-1] == "bessie"[j-1]) {
                if (dp[i-1][j-1].first > dp[i-1][j].first) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (dp[i-1][j-1].first < dp[i-1][j].first) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
                }
                dp[i][j].first += 1;
                dp[i][j].second -= cost[i-1];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][5].first << endl << -dp[n][5].second << endl;

    return 0;
}
