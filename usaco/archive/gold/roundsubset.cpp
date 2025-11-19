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

    vector<pair<int, int>> a;
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        int twos=0, fivs=0;

        int _t = t;
        while (_t>0 and (_t%2 == 0))
            twos++, _t /= 2;

        _t = t;
        while (_t>0 and (_t%5 == 0))
            fivs++, _t /= 5;

        a.push_back({twos, fivs});
    }
}

// Keep track of how many 2s and 5s each number has
// dp[i][j] where the ith number (from K) is at position j
// dp[k][2][5]
//
// Break each value in the array into 2s and 5s
// Loop through. For each value, we can either add it
// In which case dp[k+1][2+n2][5+n5] == true
// We can mark the answer as we get to it

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}
