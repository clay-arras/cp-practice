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

    if (N == 1 or N == 2)
        cout << -1 << endl;
    else if (N % 2 == 0)
        cout << N*N/4 - 1 << " " << N*N/4 + 1 << endl;
    else if (N % 2 == 1)
        cout << (N*N - 1)/2 << " " << (N*N + 1)/2 << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*

N^2 = B^2 +- A^2

If N is odd:
    B is even and A is odd
If N is even:
    B is even and A is odd
    B is even and A is even

o o e
e e e

*/
