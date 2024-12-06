#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int n; cin >> n;

    int ans = 0;
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        ans += t;
    }
    cout << (ans % 2 ? "Alice" : "Bob") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

