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
    vector<int> A;

    for (int i=0; i<N; i++) {
        int t; cin >> t;
        A.push_back(--t);
    }

    oset<int> s;
    int ix, prev;
    for (prev=A[N-1], ix=N-1; ix>=0; ix--) {
        if (prev < A[ix]) {
            ix++;
            break;
        }
        prev = A[ix];
        s.insert(A[ix]);
    }
    vector<int> An;
    copy(A.begin(), A.begin()+ix, back_inserter(An));

    int sz = (int)An.size();
    cout << sz << endl;

    for (int i=0; i<sz; i++) {
        int val = sz-i-1;
        val += s.order_of_key(An[i]);
        s.insert(An[i]);

        cout << val << " \n"[i == sz-1];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

// Increasing subsequence
// Find the longest increasing subsequence on the right
// Answer is length of subseq - total size
// O(nlogn)
// Oset

// 6
// 1 6 4 2 5 3
// 6 4 2 5 1 3
// 4 2 5 1 3 6
// 2 5 1 3 4 6
// 5 1 2 3 4 6
// 1 2 3 4 5 6
//
// 1 2 3 4 5 6
//
// 1 6 4
// 2 3 5
//
// 1 2 4 3
// 1 2 4 | 3
// 2 4 | 1 3
// How many numbers are between the first value and where we want to be
