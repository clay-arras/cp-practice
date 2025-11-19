#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

template<class T>
T lastTrue(T l, T r, function<bool(T)> f) {
    l--;
    for (T diff=r-l; diff>0; diff/=2)
        while (l + diff <= r && f(l + diff))
            l += diff;
    return l;
}

void solve() {
    long long X, Y, K; cin >> X >> Y >> K;
    for (int i=0; i<K; i++) {
        X++;
        if (X % Y == 0) {
            long long p = lastTrue(0LL, (long long)ceil(log(X)*1.0 / log(Y)) + 1,
                    (function<bool(long long)>)[&](long long k) {
                return (X % binpow(Y, k)) == 0;
            });
            X /= binpow(Y, p);
        }
        if (X == 1) {
            X = (K - i - 1) % (Y-1) + 1;
            break;
        }
    }

    cout << X << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
