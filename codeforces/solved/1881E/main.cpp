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

    A.push_back(0);
    vector<int> dp(N+1, INT_MAX);
    dp[0] = 0;
    for (int i=0; i<=N; i++) {
        if (i+1 <= N)
            dp[i+1] = min(dp[i+1], dp[i] + 1);
        if (i+A[i]+1 <= N)
            dp[i+A[i]+1] = min(dp[i+A[i]+1], dp[i]);
    }
    cout << dp[N] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

