#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N, K; cin >> N >> K;
    if (N < 62 && K > (1LL << (N-1))) {
        cout << -1 << endl;
        return;
    }
    
    vector<int> l, r;
    for (int j=N-2, it=1; j>=0; j--, it++) {
        if (j >= 62) {
            l.push_back(it);
            continue;
        }

        if ((1LL << j) & (K-1)) {
            r.push_back(it);
        } else {
            l.push_back(it);
        }
    }
    l.push_back(N);
    reverse(r.begin(), r.end());

    for (int i : l)
        cout << i << " ";
    for (int i : r)
        cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
