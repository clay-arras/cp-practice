#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type,
      less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int N; cin >> N;

    vector<vector<int>> A(N);
    for (int i=0; i<N; i++) {
        int len; cin >> len;
        A[i] = vector<int>(len);
        for (int j=0; j<len; j++)
            cin >> A[i][j];
    }

    vector<pair<int, int>> mnmx;
    vector<bool> asc;
    for (int i=0; i<N; i++) {
        int mn = INT_MAX, mx = -INT_MAX;
        bool ok = false;
        for (int j : A[i]) {
            if (mn < j) ok |= true;
            mn = min(mn, j);
            mx = max(mx, j);
        }
        mnmx.push_back({mn, mx});
        asc.push_back(ok);
    }

    oset<pair<int, int>> s;
    for (int i=0; i<N; i++) {
        if (asc[i]) s.insert({-INT_MAX, i});
        else s.insert({mnmx[i].first, i});
    }

    long long ans = 0;
    for (int i=0; i<N; i++) {
        if (asc[i]) ans += N;
        else ans += s.order_of_key({mnmx[i].second, -INT_MAX});
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
