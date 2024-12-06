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

    vector<int> K(N);
    for (int& t: K)
        cin >> t;

    set<int> s;
    int r=-1, l=0, ans=1;
    for (; l<N; l++) {
        while (!s.count(K[r+1]) and r < N-1)
            s.insert(K[++r]);
        ans = max(ans, r-l+1);
        s.erase(K[l]);
    }
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
