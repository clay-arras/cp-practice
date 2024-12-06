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
    vector<int> a(n);

    int minV = 1e9+9;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        minV = min(minV, a[i]);
    }
    if (a[0] == minV)
        cout << "BOB" << endl;
    else cout << "ALICE" << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

