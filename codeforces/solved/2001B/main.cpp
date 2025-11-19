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
    if (N % 2 == 0) {
        cout << -1 << endl;
        return;
    }
    for (int i=0; i<N; i++) {
        if (i < N/2)
            cout << i + 1 << " ";
        else
            cout << N+N/2-i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    /* open("input.txt"); */

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
