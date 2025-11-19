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
    long long sum = 0;
    for (int i=0; i<N; i++) {
        long long t; cin >> t;
        if (i % 2) sum += t;
        else sum -= t;
    }
    cout << (sum >= 0 or N%2 ? "YES" : "NO") << endl;
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
