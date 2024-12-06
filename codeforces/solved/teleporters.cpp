#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int n, c; cin >> n >> c;

    vector<int> a(n);
    for (int& t : a)
        cin >> t;

    vector<int> b;
    for (int i=0; i<n; i++) {
        b.push_back(i+1+a[i]);
    }
    sort(b.begin(), b.end());

    int ans=0;
    for (; ans < n; ans++) {
        if (c - b[ans] >= 0)
            c -= b[ans];
        else
            break;
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

