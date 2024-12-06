#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#define debug(...) 42
#endif

template<class T>
T lastTrue(T l, T r, function<bool(T)> f) {
    l--;
    for (T diff=r-l; diff>0; diff/=2)
        while (l + diff <= r && f(l + diff))
            l += diff;
    return l;
}

void solve() {
    int l, r; cin >> l >> r;
    function<bool(int)> ok = [&](int k) -> bool {
        return (k+1)*1LL*k/2 <= r-l;
    };
    int ans = 1 + lastTrue(0, r-l, ok);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
