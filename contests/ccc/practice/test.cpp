#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define open(x) freopen(x, "r", stdin)
#include <algo/debug.h>
#else
#define open(x)
#endif

struct DSU {
    vector<int> e;
    void init(int n) {
        e = vector<int> (n, -1);
    }
    int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }
    int size(int x) {
        return -get(e[x]);
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

template <class T>
struct SegTree {
    static constexpr T unit = 0;
    T f(T a, T b) { return a+b; }
    vector<T> tree; int n;

    SegTree (int i=0, T def=unit) : tree(2*i, def), n(i) {};
    void update(T val, int pos) {
        for (tree[pos+=n] = val; pos/=2;)
            tree[pos] = f(tree[2*pos], tree[2*pos+1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b+=n, e+=n; b < e; b/=2, e/=2) {
            if (b%2) ra = query(ra, tree[++b]);
            if (e%2) rb = query(tree[--b], rb);
        }
        return f(ra, rb);
    }
};

void solve() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--) {
        solve();
    }
}
