#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long double PI = 3.141592653589793238462643383279;
void solve() {
    int N; cin >> N;

    long double rad = PI*(2*N-2)/(2*N);
    long double v = PI - rad;
    long double sum = 0;
    for (int i=0; i<N/2; i++) {
        sum += cos(v);
        v = v + PI - rad;
    }
    cout << setprecision(20) << 2.0*sum + 1 << endl;
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
As N approaches infinity, the answer becomes
D = 2*N/pi

Angle = 180*(N-2)/N

*/
