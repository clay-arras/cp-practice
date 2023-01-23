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

const long long MX = 1e18;
void solve(){
    int N; cin >> N;

    /* [2, 2, 1, 0] */
    /* [0, 0, 2, 3] */
    /* 2 */

    vector<int> A(N);
    for (int &t : A)
        cin >> t;

    oset<pair<int, long long>> t1;
    vector<long long> hi(N);
    for (int i=0; i<N; i++){
        hi[i] = i-t1.order_of_key({A[i], MX});
        t1.insert({A[i], i});
    }

    oset<pair<int, long long>> t2;
    vector<long long> lo(N);
    for (int i=N-1; i>=0; i--){
        lo[i] = t2.order_of_key({A[i], -MX});
        t2.insert({A[i], i});
    }

    long long sum = 0;
    for (int i=0; i<N; i++)
        sum += hi[i]*lo[i];

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}

/* void solve(){ */
/*     int N; cin >> N; */

/*     vector<int> A(N); */
/*     for (int &t : A) */
/*         cin >> t; */

/*     reverse(A.begin(), A.end()); */
/*     oset<pair<int, int>> s; */

/*     int sum = 0; */
/*     for (int i=0; i<N; i++){ */
/*         for (int j=i+1; j<N; j++){ */
/*             if (A[i] < A[j]) */
/*                 sum += s.order_of_key({A[j], j}); */
/*         } */
/*         s.insert({A[i], i}); */
/*     } */
/*     cout << sum << endl; */
/* } */
