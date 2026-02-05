#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MX = 2e5+2;
vector<long long> adj_list[MX];
vector<long long> A;

template<class T>
T lastTrue(T l, T r, function<bool(T)> f) {
    l--;
    for (T diff=r-l; diff>0; diff/=2)
        while (l + diff <= r && f(l + diff))
            l += diff;
    return l;
}

long long dfs(long long x, long long k, long long acc=0) {
    long long curr = A[x] - acc;
    long long brid = max(0LL, k - curr);
    
    long long ch = INT_MAX;
    for (long long t : adj_list[x])
        ch = min(ch, dfs(t, 0, acc + brid));
    return (ch == INT_MAX ? curr : ch);
}

void solve() {
    long long N; cin >> N;

    A = vector<long long>(N);
    for (long long& i : A)
        cin >> i;
    for (long long i=1; i<N; i++) {
        long long p; cin >> p;
        --p;
        adj_list[p].push_back(i);
    }
    cout << lastTrue<long long>(0, 2e9, [&](long long k) {
        return dfs(0, k) >= 0;
    }) << endl;

    fill(adj_list, adj_list+N, vector<long long>{});
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

