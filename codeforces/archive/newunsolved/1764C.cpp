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

    vector<int> a(N);
    for (int& t : a)
        cin >> t;
    sort(a.begin(), a.end());

    if (a[0] == a[N-1]) {
        cout << N/2 << endl;
    } else {
        long long ans = 0;
        for (int i=0; i<N; i++) {
            while (i+1 < N and a[i+1] == a[i]) i++;
            ans = max(ans, 1LL*(i+1)*(N-i-1));
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

// Tags:
// Greedy, Graphs, 1400
//
// Greedy and sorting
// 1 2 3 4
// (4 choose 3)
//
// [1, 2, 2, 3]
// 6
// [1, 2, 2, 3, 5, 5]
// 15
// [1, 2, 2, 3, 3, 4, 4, 4, 6, 7, 7, 9]
// 66
// [1000000, 1000000, 1000000, 1000000]
// 6
//
// Order matters
// 4: 1 2 1
// 6: 1 2 1 2
// 12: 1 2 2 3 1 2 1
// 4: 4
//
// 3 : 3 less
// 9 : 6 less
// 35 : 31 less
// 2 : 4 less
//
// Basically there are no values such that the edge along them is increasing
//
// Connect all smalls to all bigs that you can
//
