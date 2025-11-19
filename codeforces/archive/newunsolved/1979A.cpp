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
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    int ans = INT_MAX;
    for (int i=1; i<N; i++)
        ans = min(ans, max(A[i], A[i-1]));

    cout << ans - 1 << endl;
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
