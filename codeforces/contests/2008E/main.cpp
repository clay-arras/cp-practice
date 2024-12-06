#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#define debug(...) 42
#endif

void solve() {
    int N; cin >> N;
    string s; cin >> s;

    vector<vector<int>> ev(N+1, vector<int>(26, 0)), od(N+1, vector<int>(26, 0));
    for (int i=1; i<=N; i++) {
        ev[i] = ev[i-1];
        od[i] = od[i-1];
        if (i%2) od[i][s[i-1]-'a']++;
        else ev[i][s[i-1]-'a']++;
    }

    if (N%2 == 0) {
        int evm = 0, odm = 0;
        for (int i=0; i<26; i++) {
            evm = max(evm, ev[N][i]);
            odm = max(odm, od[N][i]);
        }
        cout << N - evm - odm << endl;
        return;
    }

    // min replacements if we delete kth char
    function<int(int)> ok = [&](int k) -> int {
        // use kth prefix
        int evm = 0, odm = 0;
        for (int i=0; i<26; i++) {
            evm = max(evm, ev[k][i] + od[N][i] - od[k+1][i]);
            odm = max(odm, od[k][i] + ev[N][i] - ev[k+1][i]);
        }
        return N - evm - odm;
    };

    int ans = INT_MAX;
    for (int i=0; i<N; i++)
        ans = min(ans, ok(i));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
