#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#define debug(...) 42
#endif

void solve() {
    int N; cin >> N;
    string s; cin >> s;

    double sq = sqrt(N);
    if (ceil(sq) != floor(sq) || N < 4) {
        cout << "No" << endl;
        return;
    }

    int z = 0;
    for (char c : s)
        if (c-'0' == 0)
            z++;

    if (z == (sq-2)*(sq-2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
