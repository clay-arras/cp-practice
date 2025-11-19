#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, K; cin >> N >> K;

    vector<long long> pref(K);
    for (long long& t : pref)
        cin >> t;

    if (K == 1) {
        cout << "YES" << endl;
        return;
    }

    vector<long long> a(K-1);
    for (int i=1; i<K; i++) {
        a[i-1] = pref[i] - pref[i-1];
    }

    bool ok = true;
    ok &= is_sorted(a.begin(), a.end());
    ok &= (pref[0] <= a[0]*(N-K+1));
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

// N-K values left need to sum to pref[0] and be increasing
//
// Conditions:
// - Sum to pref[0]
// - Greatest value is less than or equal to a[0]
// - N-K members
