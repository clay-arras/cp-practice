#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e5+5;
long long dp[MX];
long long cnt[MX];

void solve() {
    long long N; cin >> N;

    for (long long i=0; i<N; i++) {
        long long t; cin >> t;
        cnt[t]++;
    }

    dp[0] = 0;
    for (long long i=0; i<MX; i++)
        dp[i] = max(dp[i-1], dp[i-2] + i * cnt[i]);
    cout << dp[MX-1] << endl;
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

Ok so now I look like William Lin's vimrc
Now all I have to do is code shit bunch

*/
