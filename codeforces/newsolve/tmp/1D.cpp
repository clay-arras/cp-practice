#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N, K; cin >> N >> K;

    vector<long long> f(N);
    for (long long& t : f)
        cin >> t;
    vector<long long> d(N);
    for (long long& t : d)
        cin >> t;

    vector<long long> p;
    for (long long i=0; i<N; i++) {
        p.push_back(f[i]*d[i]);
    }
    sort(p.begin(), p.end());
    cout << p << endl;
    cout << K << endl;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
