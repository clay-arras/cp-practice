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
    vector<int> H;
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        H.push_back(t);
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

// Upper bound is (h1+1)*(h2+1)...
//
// From 0 to minH
// We can iterate and add 2s to whatever until we get to that level
// It doesn't matter how many ways it takes to arrive at a level
//
// It's too slow to try every single value...
// We have to somehow generate valid sequences from starting points
//
// Is there a way to formulate whether something is reducible ... Takes O(N) time
// Observations:
// - Adjacent values can be whatever as long as we increase them similarly
// -
