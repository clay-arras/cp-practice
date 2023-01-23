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

void solve(){
    int N; cin >> N;

    vector<int> A(N);
    for (int &t : A)
        cin >> t;

    order_statistic_tree<int> t;
    for (int i=0; i<N; i++)
        t.insert(i);

    for (int i=0; i<N; i++){
        int x; cin >> x;

        auto v = t.find_by_order(--x);
        cout << A[*v] << " ";
        t.erase(v);
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
