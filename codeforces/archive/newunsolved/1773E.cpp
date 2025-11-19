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

    int tot=0;
    vector<int> a;
    vector<vector<int>> T(n, vector<int>());
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        for (int j=0; j<t; j++) {
            int k; cin >> k;

            T[i].push_back(k);
            a.push_back(k);
        }
        tot += t;
    }
    sort(a.begin(), a.end());
    map<int, int> m;
    for (int i=0; i<tot; i++) {
        m[a[i]] = i;
    }

    pair<int, int> ops = {0, 0};
    for (auto i : T) {
        int vals = 1;
        for (int j=0; j<(int)i.size()-1; j++) {
            if (m[i[j+1]] - m[i[j]] != 1) {
                vals++;
            }
        }
        ops.first += vals-1;
        ops.second += vals;
    }
    ops.second--;
    cout << ops.first << " " << ops.second << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

