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
    string s; cin >> s;

    int cnt = 0;
    int ans = 0;
    for (int i=0; i<N; i++) {
        if (i-K >= 0) {
            cnt -= s[i-K]-'0';
        }
        if (cnt == 0 && s[i] == '1')
            ans++;
        cnt += s[i]-'0';
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
