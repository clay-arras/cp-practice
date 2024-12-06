#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
struct SegTree {
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }

    vector<T> tree; int n;
    SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}

    void update(int pos, T val) {
        for (tree[pos += n] = val; pos /= 2;)
            tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, tree[b++]);
            if (e % 2) rb = f(tree[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int N; cin >> N;
    vector<int> P(N*2);

    for (int i=0; i<2*N; i++){
        int t; cin >> t;
        P[i] = --t;
    }

    int ans = 0;
    SegTree<int> T(2*N+1, 0);
    vector<int> f(N, -1);

    for (int i=0; i<2*N; i++) {
        int fPos = f[P[i]];
        if (fPos != -1) {
            T.update(fPos, 0);
            T.update(i, 0);

            ans += T.query(fPos, i+1);
            continue;
        }
        f[P[i]] = i;
        T.update(i, 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

// 3   2   4   4   1   3   2   1
// 0   1   2   3   4   5   6   7
// How do we figure out which one is between the time it's place down and the time it's picked back up
// Keep track of two segtrees
// Solution is O(NlogN)
//
// Naive solution: keep track of the indices of both ends. Loop through each pair of coords and check if they overlap manually.
// O(N^2) time.
