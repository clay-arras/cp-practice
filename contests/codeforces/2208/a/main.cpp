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
    unordered_map<int, int> cnt;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int t; cin >> t;
            cnt[t]++;
        }
    }

    int mx = 0;
    for (auto [k, v] : cnt)
        mx = max(mx, v);
    cout << (mx <= N*N - N ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
