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

    int tot = N*(N-1)/2;
    if (N%2) {
        for (int i=0; i<tot; i++)
            cout << (i % 2 ? -1 : 1) << " ";
    } else {
        bool ok = false;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (i % 2 == 0 && j == i+1)
                    cout << 0 << " ";
                else
                    cout << (ok ? -1 : 1) << " ";
                ok ^= true;
            }
            ok ^= true;
        }
    }
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
