#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N; cin >> N;

    vector<pair<string, int>> Q;
    map<string, int> m;
    for (int i=0; i<N; i++) {
        string s; cin >> s;
        int p; cin >> p;
        Q.push_back({s, p});
        m[s] += p;
    }

    int mxV = -1e9;
    for (auto [k, v] : m) {
        mxV = max(mxV, v);
    }
    set<string> names;
    for (auto [k, v] : m) {
        if (v == mxV)
            names.insert(k);
    }

    m.clear();
    for (int i=0; i<N; i++) {
        string s = Q[i].first;
        int p = Q[i].second;

        m[s] += p;
        if (m[s] >= mxV and names.count(s)) {
            cout << s << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*



*/
