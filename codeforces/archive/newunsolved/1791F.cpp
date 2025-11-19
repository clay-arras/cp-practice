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
    int n, q; cin >> n >> q;;
    vector<vector<int>> a(n, vector<int>());

    auto getSum = [](int n) {
        int sum;
        for (sum=0; n>0; sum+=n%10, n/=10);
        return sum;
    };

    for (int i=0; i<n; i++) {
        int t; cin >> t;

        int sum = t;
        while (sum >= 10) {
            a[i].push_back(sum);
            sum = getSum(sum);
        }
        a[i].push_back(sum);
    }

    SegTree<int> T(n+1, 0);
    for (int i=0; i<q; i++) {
        int query; cin >> query;
        if (query == 1) {
            int l, r; cin >> l >> r;
            --l, --r;
            T.update(l, T.tree[l+n+1] + 1);
            T.update(r+1, T.tree[r+1+n+1] - 1);
        } else {
            int x; cin >> x;
            --x;
            int val = T.query(0, x+1), sz = (int)a[x].size()-1;
            cout << a[x][min(sz, val)] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

