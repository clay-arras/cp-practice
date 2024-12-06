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

    map<tuple<int, int, int>, long long> diff, same;
    for (int i=1; i<N-1; i++) {
        diff[{-1, A[i], A[i+1]}]++;
        diff[{A[i-1], -1, A[i+1]}]++;
        diff[{A[i-1], A[i], -1}]++;
        same[{A[i-1], A[i], A[i+1]}]++;
    }

    long long diffs = 0, sames = 0;
    for (auto [k, v] : diff)
        diffs += v*1LL*(v-1)/2LL;
    for (auto [k, v] : same)
        sames += v*1LL*(v-1)/2LL;

    cout << diffs - 3LL*sames << endl;;
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
