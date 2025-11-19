#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long mxV = 1e18+9;
long long dist(pair<long long, long long> a, pair<long long, long long> b) {
    return pow(abs(a.first - b.first), 2) + pow(abs(a.second - b.second), 2);
}
void solve() {
    int H, G; cin >> H >> G;
    vector<pair<long long, long long>> cH(H), cG(G);
    for (auto& [f, s] : cH)
        cin >> f >> s;
    for (auto& [f, s] : cG)
        cin >> f >> s;

    vector<vector<vector<long long>>> dp
        (H+1, vector<vector<long long>>(G+1, vector<long long>(2, mxV)));
    dp[1][0][0] = 0;

    for (int i=0; i<=H; i++) {
        for (int j=0; j<=G; j++) {
            if (i > 1) {
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + dist(cH[i-1], cH[i-2]));
            }
            if (j > 1) {
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + dist(cG[j-1], cG[j-2]));
            }
            if (i > 0 and j > 0) {
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + dist(cG[j-1], cH[i-1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + dist(cH[i-1], cG[j-1]));
            }
        }
    }
    cout << dp[H][G][0] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

/*



*/

