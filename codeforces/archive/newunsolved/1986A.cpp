#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    int ans = INT_MAX;
    for (int i=1; i<=10; i++) {
        int val = abs(i - x1) + abs(i - x2) + abs(i - x3);
        ans = min(ans, val);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
