#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int n, m, k; cin >> n >> m >> k;

    int mxV = 0;
    int v = ceil(n*1.0/k);
    int vcount = 0;
    for (int i=0; i<m; i++) {
        int t; cin >> t;
        mxV = max(mxV, t);
        if (t == v)
            vcount++;
    }
    if (mxV > v or (vcount > n % k and n % k))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
