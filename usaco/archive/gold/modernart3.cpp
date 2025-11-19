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

    /* vector<int> A(N); */
    /* for (auto& t : A) */
    /*     cin >> t; */
    vector<pair<int, int>> A(N);
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        A[i] = {t, i};
    }

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



*/
