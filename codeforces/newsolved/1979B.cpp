#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int x, y; cin >> x >> y;
    for (int i=0; i<32; i++) {
        if ((x ^ y) & (1 << i)) {
            cout << (1 << i) << endl;
            return;
        }
    }
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
