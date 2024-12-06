#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int n; cin >> n;
    if ((n+1) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int a_1 = 3*(n+1)/2;
    int a_n = 3*(n+1)/2 + n-1;

    int a=1, b=2*n;
    for (int sum=a+b; sum<=a_n; a+=2, b--, sum=a+b)
        cout << a << " " << b << endl;
    for (int sum=a_1, a=2; sum<2*n+1; sum++, a+=2)
        cout << sum-a << " " << a << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

// Integer N
// Sum from 1 to 2N
// Each pair has to be consecutive and there are N pairs
// N(a + (a+n-1)) / 2 = 2*N(2*N+1)/2
// (N+1)%2 == 0
