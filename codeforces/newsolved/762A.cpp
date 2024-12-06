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

oset<long long> dv;
void divisors(long long N) {
    for (long long i=1; i<=sqrt(N); i++) {
        if (N%i == 0) {
            dv.insert(i);
            if (N/i != i)
                dv.insert(N/i);
        }
    }
}

void solve() {
    long long N, K; cin >> N >> K;
    divisors(N);

    auto it = dv.find_by_order(K-1);
    cout << (it == dv.end() ? -1 : *it) << endl;
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

*/
