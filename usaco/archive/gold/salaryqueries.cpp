#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

template<class T>
using order_statistic_tree = tree<T, null_type,
      less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 0;
void solve(){
    int N, Q; cin >> N >> Q;

    order_statistic_tree<pair<int, int>> t;
    vector<int> a;

    for (int i=0; i<N; i++){
        int x; cin >> x;
        a.push_back(x);
        t.insert({x, i});
    }

    while (Q--){
        char opt; cin >> opt;

        if (opt == '!'){
            int k, x; cin >> k >> x;
            --k;
            t.erase({a[k], k});
            t.insert({x, k});
            a[k] = x;
        }else if (opt == '?'){
            int a, b; cin >> a >> b;
            cout << t.order_of_key({b+1, MX}) - t.order_of_key({a, MX}) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
