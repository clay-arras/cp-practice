#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int n, m, d; cin >> n >> m >> d;

    vector<int> p(n+1);
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        p[--t] = i;
    }
    vector<int> a(m);
    for (int& t : a)
        cin >> t;

    vector<int> arr(m);
    for (int i=0; i<m; i++) {
        arr[i] = p[--a[i]];
    }

    int ans = 1e9+18;
    for (int i=1; i<m; i++) {
        ans = min(ans, arr[i]-arr[i-1]);
        if (d+1 < n)
            ans = min(ans, d+1-(arr[i]-arr[i-1]));
    }

    // d = 4
    //
    /* 5 2 4 */
    /* 5 4 3 2 1 */
    /* 5 2 */

    /* [0, 3] */
    /* 3 3 4 */
    /* 2 */
    // Hit the edge of the permuntation

    cout << max(0, ans) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

//    0 1 2 3 4 5
// p=[4,2,1,3,6,5] and d=2
//
// a=[2,3,6] is not good
// pos(2) = 1-3
// pos(3) = 3-5
// pos(6) = 4-6
//
// Simplify:
// a=[1,2,3]
// p=[2,3,4]
//
// p=[2,3,4]
// Two conditions:
// - strictly increasing
// - diff between two consecutive values needs to be <= d
//
// check two conditions first
// take d-max(conseq diff)
// take min(conseq diff)
//
// Operation: we can increase or decrease a value's pos
// - While influencing other pos
//
// Minimum distance such that we get out of the range
// O(N) to check if good
//
// a=[2,6,5] is good
// a=[1,6,3] is good
//
//
// 5 4 3 2 1
// 5 2
//
// d = 4
// p=[0, 3]
