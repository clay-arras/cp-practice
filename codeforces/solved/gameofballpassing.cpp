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

    long long sum = 0, mx = 0;
    bool zero = false;
    for (int i=0; i<N; i++) {
        long long t; cin >> t;
        sum += t;
        mx = max(mx, t);
        zero |= (bool)t;
    }
    if (!zero)
        cout << 0 << endl;
    else
        cout << (2*mx <= sum ? 1 : 2*mx - sum) << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*

Read the question wrong
They don't have to be adjacent

Do the most you can with one uneven
If you reduce completely go again

1 2 1 2
. .



9 2 3 8
22


*/
