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

    vector<string> cmp;
    for (int i=0; i<2*N-2; i++) {
        string s; cin >> s;
        if ((int)s.size() == N-1)
            cmp.push_back(s);
    }
    reverse(cmp[0].begin(), cmp[0].end());
    cout << (cmp[0] == cmp[1] ? "YES" : "NO") << endl;
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
