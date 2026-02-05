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

    vector<int> L(N), R(N), C(N);
    for (int& i : L)
        cin >> i;
    for (int& i : R)
        cin >> i;
    for (int& i : C)
        cin >> i;

    sort(L.rbegin(), L.rend());
    multiset<int> rt(R.begin(), R.end());
    vector<int> rgs;
    for (int i=0; i<N; i++) {
        auto it = rt.lower_bound(L[i]);
        rgs.push_back(*it - L[i]);
        rt.erase(it);
    }

    sort(C.begin(), C.end());
    sort(rgs.rbegin(), rgs.rend());
    long long ans = 0;
    for (int i=0; i<N; i++)
        ans += rgs[i]*1LL * C[i];
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
