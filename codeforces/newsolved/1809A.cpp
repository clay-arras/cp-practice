#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    string s; cin >> s;

    map<char, int> m;
    for (auto c : s)
        m[c]++;

    for (auto [k, v] : m) {
        if (v == 4) {
            cout << -1 << endl;
            return;
        }
        if (v == 3) {
            cout << 6 << endl;
            return;
        }
    }
    cout << 4 << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*



*/
