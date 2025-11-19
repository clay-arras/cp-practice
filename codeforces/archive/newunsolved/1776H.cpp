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

    map<int, int> a;
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        a[t] = i;
    }
    for (int& t : b)
        cin >> t;

    int prev = a[b[n-1]], cnt = 0;
    for (int i=n-2; i>=0; i--) {
        if (a[b[i]] > prev)
            break;
        prev = a[b[i]];
        cnt++;
    }
    cout << n - cnt - 1 << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

// Count number of relative places and then subtract from N
