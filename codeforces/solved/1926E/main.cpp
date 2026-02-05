#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N, K; cin >> N >> K;

    long long roll = 0, ans = 0;
    for (long long i=0;; i++) {
        long long pw = (1LL << (i+1));
        long long curr = (N - (1LL << i))/pw + 1;
        if (K <= roll + curr) {
            ans = pw * (K-roll) - (1LL << i);
            break;
        }
        roll += curr;
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

