#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N; cin >> N;
    long long val = sqrt(N);

    if (val * val > N) {
        cout << val - 1 << endl;
    } else if (val * val < N) {
        cout << val << endl;
    } else {
        cout << val - 1 << endl;
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

/*



*/
