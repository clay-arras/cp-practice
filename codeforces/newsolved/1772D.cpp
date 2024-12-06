#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e9+10;
void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int& t : a)
        cin >> t;

    int mx=MX, mn=0;
    for (int i=0; i+1<n; i++) {
        int x = (a[i] + a[i+1])/2;
        int y = (a[i] + a[i+1]+1)/2;

        if (a[i] < a[i+1])
            mx = min(mx, x);
        if (a[i] > a[i+1])
            mn = max(mn, y);
    }
    cout << (mn <= mx ? mn : -1 ) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

// Cases:
// All values can be made equal: take the middle value
// All values are increasing: nothing
// All values are decreasing: take some arbitrarily large number
// Increasing and then decreasing
// Decreasing and then increasing
//
// 3000 5200 7500 8000 10 5
// 1005 1195 3495 3995 3995 4000
// (8000 + 10) / 2
// 4005
// 4100
// 1100 1100 3400 2900 4090 4095
