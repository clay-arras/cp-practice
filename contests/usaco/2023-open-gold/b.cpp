#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e5+5;
const int M = 6;
string b = "bessie";

pair<int, int> dp[MX][M+5];
void solve() {
    string t; cin >> t;
    string s = "";
    bool ok = false;
    for (char c : t) {
        if (c == 'b' and !ok)
            ok = true;
        if (ok) s += c;
    }
    int N = (int)s.length();
    cout << s << endl;

    vector<int> cost(N);
    for (int& t : cost)
        cin >> t;

    dp[0][0] = {1, 0};
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (j == 0 and i != 0 and s[i] == 'b')
                dp[i][j] = max(dp[i][j], {dp[i-1][j].first, 0});
            if (i != 0)
                dp[i][j] = max(dp[i][j], {dp[i-1][j].first, dp[i-1][j].second - cost[i]});
            if (j != 0 and i != 0 and s[i] == b[j] and dp[i-1][j-1].first+1 != dp[i][j-1].first)
                dp[i][j] = max(dp[i][j], {dp[i][j-1].first, dp[i][j-1].second + (bool)dp[i][j-1].first*cost[i]});
        }
    }

    for (int i=0; i<=N; i++) {
        cout << s[i] << ": ";
        for (int j=0; j<=M; j++)
            cout << setw(9) << dp[i][j].first << "," << setw(3) << dp[i][j].second << " ";
        cout << endl;
    }

    cout << dp[N-1][M-1] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*
    if (i != 0)
        dp[i][j] = max(dp[i][j], {dp[i-1][j].first, dp[i-1][j].second - cost[i] * (s[i] != b[j])});
    if (j != 0)
        dp[i][j] = max(dp[i][j], {dp[i][j-1].first, min(0, dp[i][j-1].second + cost[i] * (s[i] == b[j]))});

 */
