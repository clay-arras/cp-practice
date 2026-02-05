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
    vector<vector<int>> A(N, vector<int>(2, 0));
    for (int i=0; i<N; i++)
        cin >> A[i][0];
    for (int i=0; i<N; i++)
        cin >> A[i][1];

    vector<int> mn_pref(N+1, INT_MAX), mx_pref(N+1, -INT_MAX);
    vector<int> mn_suff(N+1, INT_MAX), mx_suff(N+1, -INT_MAX);

    mn_pref[0] = mx_pref[0] = A[0][0];
    mn_suff[N] = mx_suff[N] = A[N-1][1];
    for (int i=1; i<=N; i++) {
        mn_pref[i] = min(mn_pref[i-1], A[i-1][0]);
        mx_pref[i] = max(mx_pref[i-1], A[i-1][0]);
    }
    for (int i=N-1; i>=0; i--) {
        mn_suff[i] = min(mn_suff[i+1], A[i][1]);
        mx_suff[i] = max(mx_suff[i+1], A[i][1]);
    }

    unordered_map<int, int> intv;
    for (int i=0; i<N; i++) {
        int l = min(mn_pref[i+1], mn_suff[i]);
        int r = max(mx_pref[i+1], mx_suff[i]);

        if (intv.count(l)) intv[l] = min(intv[l], r);
        else intv[l] = r;
    }

    int min_r = INT_MAX;
    for (int l=2*N; l>=1; l--) {
        if (!intv.count(l))
            continue;

        if (intv[l] >= min_r)
            intv.erase(l);
        else min_r = min(min_r, intv[l]);
    }

    long long ans = 0;
    int prev_l = 0;
    for (int l=1; l<=2*N; l++) {
        if (!intv.count(l))
            continue;
        ans += (l - prev_l)*1LL * (2*N - intv[l] + 1);
        prev_l = l;
    }
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
