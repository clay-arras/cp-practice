#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long n; cin >> n;
    long long a = n/2, b=2*n - a;

    if ((a^b) != n or (a+b)/2 != n)
        cout << -1 << endl;
    else
        cout << a << " " << b << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

