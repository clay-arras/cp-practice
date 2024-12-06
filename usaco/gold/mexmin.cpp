#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, K; cin >> N >> K;

    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    multiset<int> w, val;

    int maxVal = 0;
    for (int i=0; i<K; i++) {
        w.insert(A[i]);
        maxVal = max(maxVal, A[i]);
    }
    for (int i=0; i<maxVal+5; i++) {
        if (!w.count(i))
            val.insert(i);
    }

    int ans = INT_MAX;
    for (int i=K; i<N; i++) {
        if (!val.empty())
            ans = min(ans, *val.begin());

        w.erase(w.find(A[i-K]));
        w.insert(A[i]);
        val.erase(A[i]);

        if (!w.count(A[i-K]))
            val.insert(A[i-K]);
    }
    ans = min(ans, *val.begin());
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// 1. Make a set to keep track of sliding window
// 2. Make another set to keep track of all the values that aren't in the sliding window
