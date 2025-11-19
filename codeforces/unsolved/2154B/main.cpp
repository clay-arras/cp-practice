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

    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    vector<int> pref(N, 0);
    for (int i=0; i<N; i++) {
        pref[i] = A[i];
        if (i) pref[i] = max(pref[i], pref[i-1]);
    }
    for (int i=0; i<N; i++) {
        if (i % 2)
            A[i] = pref[i];
    }

    int ans = 0;
    for (int i=0; i<N-1; i++) {
        if (i % 2 == 0) {
            if (A[i] >= A[i+1]) {
                int decr = A[i] - A[i+1] + 1;
                ans += decr;
                A[i] -= decr;
            }
        } else {
            if (A[i] <= A[i+1]) {
                int decr = A[i+1] - A[i] + 1;
                ans += decr;
                A[i+1] -= decr;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
