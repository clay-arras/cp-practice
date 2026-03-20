#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
T firstTrue(T l, T r, function<bool(T)> f) {
    r++;
    while (l < r) {
        T mid = l + (r - l) / 2;
        if (f(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve() {
    long long X, Y, K; cin >> X >> Y >> K; 
    for (int i=0; i<X; i++) {
        K = firstTrue<long long>(1, 1e14, [&](long long t) {
            return t - (t / Y) >= K;
        });
    }
    cout << (K > 1e12 ? -1 : K) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
