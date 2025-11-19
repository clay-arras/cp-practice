#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
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
    int N; cin >> N;

    vector<long long> L(N);
    vector<long long> R(N);
    map<long long, long long> m;

    for (int i=0; i<N; i++) {
        cin >> L[i];
        m[L[i]] = i;
    }

    vector<long long> v(N);
    for (int i=0; i<N; i++) {
        cin >> R[i];
        v[i] = m[R[i]];
    }
    reverse(v.begin(), v.end());

    long long sum = 0;
    oset<long long> s;
    for (int i=0; i<N; i++) {
        s.insert(v[i]);
        sum += s.order_of_key(v[i]);
    }

    long long ans = sum;
    for (int i=0; i<N; i++) {
        sum += 2*v[i]-N+1;
        ans = min(ans, sum);
    }

    m = map<long long, long long>();
    for (int i=0; i<N; i++) {
        m[R[i]] = i;
    }

    v = vector<long long>(N);
    for (int i=0; i<N; i++) {
        cin >> L[i];
        v[i] = m[L[i]];
    }
    reverse(v.begin(), v.end());

    sum = 0;
    s = oset<long long>();
    for (int i=0; i<N; i++) {
        s.insert(v[i]);
        sum += s.order_of_key(v[i]);
    }

    ans = min(ans, sum);
    for (int i=0; i<N; i++) {
        sum += 2*v[i]-N+1;
        ans = min(ans, sum);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

// Let's assume that we are going to iterate over all possible cyclic shifts
// That means that we need a O(logN) way to find the number of crossing pairs in a configuration
// Reverse the second array, and it simplifies to the one we did last time
//
// Sum of values from the two ranges (non inclusive)
// From one end to the middle, from the middle to the other end
// 5    1
// 4    3
// 1    2
// 3    5
// 2    4
//
// 1: 2, 0
// 2: 4, 2
// 3: 3, 1
// 4: 1, 4
// 5: 0, 3
//
// // The left side is positive, the right side is negative
// If the sum is positive then we add and that's the number of crossed
//
// O(N^2)
