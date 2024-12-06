#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#define debug(...) 42
#endif

void solve() {
    int on, tw; cin >> on >> tw;
    if (on % 2) {
        cout << "NO" << endl;
        return;
    }
    if (tw % 2 == 0) {
        cout << "YES" << endl;
        return;
    }
    if (on >= 2) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
