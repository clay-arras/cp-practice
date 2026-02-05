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
    int N, T, K; cin >> N >> T >> K;

    auto ans = firstTrue<int>(1, N, [&](int t) {
        cout << "? 1 " << t << endl;
        cout.flush();
        int sum; cin >> sum;
        return (t - sum) >= K;
    });
    cout << "! " << ans << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
