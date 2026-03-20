#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    map<int, int> cnt;
    for (int i : A)
        cnt[i]++;

    vector<int> dp(N+1, 2e9);
    dp[1] = 1;
    bool ok = true;
    for (auto [k, v] : cnt) {
        if (ok) {
            ok = false;
            continue;
        }
        vector<int> pdp(N+1, 2e9);
        for (int i=0; i<=N; i++) {
            if (i-1 >= 0)
                pdp[i] = min(pdp[i], dp[i-1] + 1); 
            if (i+v <= N)
                pdp[i] = min(pdp[i], dp[i+v]);
        }
        dp = pdp;
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
