#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

string read() {
    string s; cin >> s;
    string ret = "";
    for (char c : s) {
        if (c == '1') continue;
        if (c == '0') ret.clear();
        if (c != '+') c = '*';
        ret += c;
    }
    return ret;
}

const int MOD = 1e9+7;
void solve() {
    int N; cin >> N;
    string sb = read(), se = read();
    int blen = (int)sb.size(), elen = (int)se.size();

    vector<vector<vector<long long>>> dp
        (blen+1, vector<vector<long long>>(elen+1, vector<long long>(2, 0)));
    dp[0][0][1] = 1;
    for (int i=0; i<=blen; i++) {
        for (int j=0; j<=elen; j++) {
            if (i < blen)
                dp[i+1][j][0] = (dp[i][j][1] + dp[i][j][0])%MOD;
            if (j < elen) {
                dp[i][j+1][1] = dp[i][j][1];
                if (sb[i-1] != se[j])
                    dp[i][j+1][1] = (dp[i][j+1][1] + dp[i][j][0])%MOD;
            }
        }
    }
    cout << (dp[blen][elen][0] + dp[blen][elen][1])%MOD << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
