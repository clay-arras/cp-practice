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
    vector<int> a;

    for (int i=0; i<n; i++) {
        int t; cin >> t;
        a.push_back(t);
    }

    map<int, int> m;
    set<int> s;
    for (int i=0; i<n; i++) {
        int t = a[i];
        if (!s.count(t)) {
            s.insert(t);
        }
        m[t]++;
    }

    int ans = 0;
    for (int i : s) {
        ans += max(0, m[i] - m[i-1]);
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

