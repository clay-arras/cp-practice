#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    if ((p1+p2+p3) % 2) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    int val = max(0, ((p1+p2)-p3)/2);
    ans += val;
    p1 -= val;
    p2 -= val;
    ans += min(p1+p2, p3);

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

/*



*/
