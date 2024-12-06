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
    vector<int> A(2*N);

    for (int& t : A)
        cin >> t;

    SegTree<int> L(N), R(N);
    for (int i=0; i<2*N; i++) {
        if (i < N)
            L.update(i, A[i]^1);
        else
            R.update(i-N, A[i]^1);
    }

    int Linv = 0, Rinv = 0;
    for (int i=0; i<N; i++) {
        if (A[i] == 1)
            Linv += L.query(i, N);
    }
    for (int i=0; i<N; i++) {
        if (A[i+N] == 1)
            Rinv += R.query(i, N);
    }
    int maxAns = abs(Linv - Rinv);

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
