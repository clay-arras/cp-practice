#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N, X, P; cin >> N >> X >> P;

    bool ans = false;
    long long t = min(2*N, P);
    for (long long i=1; i<=t; i++)
        ans |= ((X+i*(i+1)/2)%N == 0);
    cout << (ans ? "Yes" : "No") << endl;
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
