#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long b, c, d; cin >> b >> c >> d;
    long long bex = ((b | d) ^ d);
    if ((bex | c) != c) {
        cout << -1 << endl;
        return;
    }
    long long a = ((d^b) | bex);
    if ((a | b) - (a & c) != d) {
        cout << -1 << endl;
        return;
    }
    cout << a << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
