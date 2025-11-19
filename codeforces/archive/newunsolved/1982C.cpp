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
    int N, L, R; cin >> N >> L >> R;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    vector<long long> pref(N+1);
    for (int i=0; i<N; i++)
        pref[i+1] += pref[i] + A[i];

    int ans = 0;
    for (int i=0; i<N; i++) {
        if (A[i] > R) {
            continue;
        } else if (A[i] >= L && A[i] <= R) {
            ans++;
        } else if (A[i] < L) {
            int val = firstTrue(i, N-1, (function<bool(int)>)[&](int k) {
                return pref[k+1] - pref[i] >= L*1LL;
            });
            if (pref[val+1] - pref[i] <= R && pref[val+1] - pref[i] >= L) {
                ans++;
                i = val;
            }
        }
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
