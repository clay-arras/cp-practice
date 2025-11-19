#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

void solve() {
    int N; cin >> N;

    vector<pair<int, int>> ans;
    for (int i=2; i<=N; i++) {
        int val = 1, prev = 1;
        while (val != i) {
            cout << "? " << i << " " << val << endl;
            cout.flush();
            prev = val;
            cin >> val;
        }
        ans.push_back({i, prev});
    }

    cout << "! ";
    for (auto [f, s] : ans)
        cout << f << " " << s << " ";
    cout << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
