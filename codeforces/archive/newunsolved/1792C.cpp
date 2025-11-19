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

    vector<int> p(n);
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        p[--t] = i;
    }

    int hi = ceil((n-1.0)/2), lo = (n-1.0)/2;
    int hiPos = p[hi], loPos=p[lo];

    if (hiPos < loPos) {
        cout << (n+1)/2 << endl;
        return;
    }

    int ans = 0;
    for (int i=1; i<=n/2; i++) {
        int hiNew = p[hi+i], loNew = p[lo-i];
        if (hiNew < hiPos or loNew > loPos) {
            ans = (n+1)/2 - i;
            break;
        }
        hiPos = hiNew, loPos = loNew;
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

