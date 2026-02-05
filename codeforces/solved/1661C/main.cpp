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
    int N; cin >> N;
    vector<int> h(N);
    for (auto& i : h)
        cin >> i;

    int mx = *max_element(h.begin(), h.end());
    auto ok = [&](long long x) {
        long long on = ceil(x*1.0/2);
        long long tw = x/2;

        bool ok = true;
        for (int i=0; i<N; i++) {
            long long diff = mx - h[i];

            long long mn_t = min(tw, diff/2);
            tw -= mn_t;
            diff -= 2*mn_t;

            long long mn_o = min(on, diff);
            on -= mn_o;
            diff -= mn_o;

            if (diff != 0)
                ok = false;
        }
        if (ok) return true;

        on = ceil(x*1.0/2);
        tw = x/2;

        ok = true;
        for (int i=0; i<N; i++) {
            long long diff = (mx+1) - h[i];

            long long mn_t = min(tw, diff/2);
            tw -= mn_t;
            diff -= 2*mn_t;

            long long mn_o = min(on, diff);
            on -= mn_o;
            diff -= mn_o;

            if (diff != 0)
                ok = false;
        }
        return ok;
    };

    cout << firstTrue<long long>(0, 1e16, ok) << endl;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
