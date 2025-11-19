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

    map<int, int> m;
    vector<vector<int>> a(n, vector<int>());
    for (int i=0; i<n; i++) {
        int k; cin >> k;

        for (int j=0; j<k; j++) {
            int p; cin >> p;
            m[p]++;
            a[i].push_back(p);
        }
    }

    bool ok = false;
    for (int i=0; i<n; i++) {
        int totK = (int)a[i].size();
        for (auto j : a[i]) {
            if (m[j] > 1) {
                totK--;
            }
        }
        if (!totK)
            ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

