#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type,
      less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, D; cin >> N >> D;

    vector<pair<int, int>> C;
    for (int i=0; i<N; i++) {
        int x, h; cin >> x >> h;
        C.push_back({h, x});
    }
    sort(C.rbegin(), C.rend());

    oset<pair<int, int>> L, R;
    int cnt = 0;
    for (int i=0; i<N; i++) {
        int il = L.order_of_key({C[i].second, -C[i].first});
        int ir = R.order_of_key({C[i].second, C[i].first});
        auto itl = lower_bound(L.begin(), next(L.begin(), il), -2*C[i].first);
        auto itr = lower_bound(R.begin(), next(R.begin(), ir), 2*C[i].first);

        if (abs((*itl).second - C[i].second) <= D and abs((*itr).second - C[i].second) <= D)
            cnt++;

        L.insert({C[i].second, -C[i].first});
        R.insert({C[i].second, C[i].first});
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Algorithm:
Use Upper bound and Lower bound

First element X that is

*/
