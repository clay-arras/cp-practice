#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct SMeta {
    int val = -INT_MAX;
    int offset = 0;
    int idx = 0;

    bool operator<(const SMeta& other) const {
        if (val + offset == other.val + other.offset)
            return idx > other.idx;
        return val + offset < other.val + other.offset;
    };
};

template<class T>
struct SegTree {
    static constexpr T unit = {};
    T f(T a, T b) { 
        SMeta anew{a.val, a.offset, a.idx};
        SMeta bnew{b.val, a.offset + b.offset, b.idx};
        return max(anew, bnew); 
    }
    vector<T> tree; int n;
    SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}
    void update(int pos, T val) {
        for (tree[pos += n] = val; pos /= 2;)
            tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
    }
    T query(int b, int e) {
        e++;
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
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    SegTree<SMeta> stree(N);
    for (int i=0; i<N; i++) 
        stree.update(i, SMeta{A[i], 1, i});

    set<int> s;
    for (int i=0; i<N; i++) {
        auto top = stree.query(0, N-1);
        s.insert(top.val + top.offset);
        stree.update(top.idx, SMeta{-INT_MAX, 0, i});
    }
    for (auto it=s.rbegin(); it!=s.rend(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
