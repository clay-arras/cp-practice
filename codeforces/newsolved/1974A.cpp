#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int a, b; cin >> a >> b;
    int s = ceil(b*1.0/2);

    a = max(0, a - (15*s - 4*b));
    s += ceil(a*1.0/15);
    cout << s << endl;
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
