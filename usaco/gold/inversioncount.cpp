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

    vector<pair<int, int>> A(N);
    for (int i=0; i<N; i++){
        int t; cin >> t;
        A[i] = {t, i};
    }

    order_statistic_tree<pair<int, int>> t;
    reverse(A.begin(), A.end());

    long long sum = 0;
    for (int i=0; i<N; i++){
        sum += t.order_of_key(A[i]);
        t.insert(A[i]);
    }
    cout << sum << endl;

    // Maintain one OST
    // Construct the OST backwards with the highest i in A
    // For each addition, find the number of elements and add it to the sum

}

// 2, 3, 8, 6, 1
// 1
// 1, 6
// 1, 6, 8
// 1, 3, 6, 8
// 1, 2, 3, 6, 8

// 1 + 2 + 1 + 1


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
