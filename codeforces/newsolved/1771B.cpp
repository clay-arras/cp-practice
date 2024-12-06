#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N, M; cin >> N >> M;

    map<long long, long long> m;
    for (long long i=1; i<=N; i++)
        m[i] = N+1;
    for (long long i=0; i<M; i++) {
        long long x, y; cin >> x >> y;
        if (x < y)
            swap(x, y);
        m[y] = min(x, m[y]);
    }
    long long minV = N+1;
    for (long long i=N; i>=1; i--) {
        m[i] = min(minV, m[i]);
        minV = min(minV, m[i]);
    }
    long long ans = 0;
    for (long long i=1; i<=N; i++) {
        ans += m[i]-i;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
