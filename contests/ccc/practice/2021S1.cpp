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

    vector<int> h;
    for (int i=0; i<N+1; i++) {
        int t; cin >> t;
        h.push_back(t);
    }
    vector<int> w;
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        w.push_back(t);
    }

    long long sum = 0;
    for (int i=0; i<N; i++) {
        sum += w[i]*(h[i] + h[i+1]);
    }
	printf("%lld%s", (sum/2), (sum&1 ? ".5\n" : "\n"));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

