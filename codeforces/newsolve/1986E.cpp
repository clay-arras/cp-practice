#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, K; cin >> N >> K;
    vector<int>A(N);
    for (int& i : A)
        cin >> i;

    map<int, vector<int>> v;
    for (int i : A)
        v[i % K].push_back(i);

    int ok = 0, ans = 0;
    for (int i=0; i<K; i++) {
        if (v[i].empty())
            continue;

        sort(v[i].begin(), v[i].end());
        int len = (int)v[i].size();
        int b = 0;
        for (int j=1; j<len; j+=2)
            b += (v[i][j] - v[i][j-1])/K;

        if (len == 1) {

        } else if (len % 2){
            int a = 0;
            vector<int> diff(len - 1);
            for (int j=1; j<len; j++)
                diff[j-1] = v[i][j] - v[i][j-1];
            vector<vector<int>> dp(len+2, vector<int>(2, INT_MAX));
            dp[0][0] = 0;
            dp[0][1] = 0;
            dp[1][1] = 0;
            for (int j=0; j<=len+1; j++) {
                if (j-2 >= 0 && dp[j-2][0] != INT_MAX)
                    dp[j][0] = min(dp[j][0], dp[j-2][0] + diff[j-2]);
                if (j-3 >= 0 && dp[j-3][0] != INT_MAX)
                    dp[j][1] = min(dp[j][1], dp[j-3][0] + diff[j-3]);
                if (j-2 >= 0 && dp[j-2][1] != INT_MAX)
                    dp[j][1] = min(dp[j][1], dp[j-2][1] + diff[j-2]);
            }
            a = min(dp[len][0]/K, dp[len][1]/K);
            ans += min(a, b);
        } else {
            ans += b;
        }

        ok += len % 2;
    }
    cout << (ok <= 1 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
