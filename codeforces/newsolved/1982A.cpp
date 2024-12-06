#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << (x1 > y1 == x2 > y2 ? "YES" : "NO" ) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
