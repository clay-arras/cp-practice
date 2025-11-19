#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

vector<long long> pref, T;
long long i;
bool ok(long long x) { return pref[x] - pref[i] <= T[i]; }
long long lastTrue(long long lo, long long hi) {
    lo--;
    for (long long dif=hi-lo; dif>0; dif/=2) {
        while (lo + dif <= hi && ok(lo + dif)) { lo += dif; }
    }
    return lo;
}

// 1 1 1 1 1 0 0 0 0
// pref[x] <= T[i]

void solve() {
    long long N; cin >> N;

    T = vector<long long>(N, 0);
    for (long long& i : T)
        cin >> i;
    vector<long long> A(N);
    for (long long& i : A)
        cin >> i;

    pref = vector<long long>(N+1, 0);
    for (i=1; i<=N; i++)
        pref[i] = pref[i-1] + A[i-1];

    vector<long long> K(N+1, 0), R(N, 0);
    for (i=0; i<N; i++) {
        if (T[i] >= pref[N] - pref[i]) {
            K[i]++, K[N]--;
        } else {
            long long v = lastTrue(1LL, N);
            R[v] += T[i] - (pref[v] - pref[i]);
            K[i]++, K[v]--;
        }
    }

    long long sum = 0;
    for (i=0; i<N; i++) {
        sum += K[i];
        cout << sum * A[i] + R[i] << " ";
    }
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
