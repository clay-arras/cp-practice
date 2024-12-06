#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, M, R, C; cin >> N >> M >> R >> C;

    if (R == 1 and C == 1) {
        cout << "aa\nad" << endl;
    }
    if (R == 0 and C == 0) {
        cout << "ab\ncd" << endl;
        return;
    }
    if (R == 1 and C == 0) {
        cout << "ab\nad" << endl;
        return;
    }
    if (R == 0 and C == 1) {
        cout << "aa\nbd" << endl;
        return;
    }
    if (R == 2 and C == 2) {
        cout << "aa\naa" << endl;
        return;
    }
    cout << "IMPOSSIBLE" << endl;
}

// aa
// aa
//
// Case: R = 0
// Do C letters on one half
//
// Case: R = 1
// - if C is even and M is even: C + 2 <= M
// - if C is odd and M is even: IMPOSSIBLE
// - if C is even and M is odd: C + 3 <= M
// - if C is odd and M is odd: C + 2 <= M
//
// Case: R = 2
// - if C is even and M is even: no limit
// - if C is even and M is odd: C + 1 <= M
// - if C is odd and M is odd: no limit
// - if C is odd and M is even: IMPOSSIBLE

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

