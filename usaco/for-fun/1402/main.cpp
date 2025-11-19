#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
struct MaxSegTree {
    static constexpr T unit = -INT_MAX;
    T f(T a, T b) { return max(a, b); }
    vector<T> tree; int n;
    MaxSegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}
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

template<class T>
struct MinSegTree {
    static constexpr T unit = INT_MAX;
    T f(T a, T b) { return min(a, b); }
    vector<T> tree; int n;
    MinSegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}
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

vector<int> L, R, A;
int N;

void compute_bounds() {
    vector<int> cct = A;
    sort(cct.begin(), cct.end());
    unordered_map<int, int> cc;
    int M = 0;
    for (int i : cct)
        if (!cc.count(i))
            cc[i] = M++;

    MinSegTree<int> ntree(M);
    for (int i=0; i<N; i++)
        if (ntree.tree[M+cc[A[i]]] > i+N)
            ntree.update(cc[A[i]], i+N);

    R = vector<int>(N);
    for (int i=N-1; i>=0; i--) {
        int diff = ntree.query(0, cc[A[i]]+1);
        R[i] = diff - i;
        if (ntree.tree[M+cc[A[i]]] > i)
            ntree.update(cc[A[i]], i);
    }

    MaxSegTree<int> xtree(M);
    for (int i=0; i<N; i++)
        if (xtree.tree[M+cc[A[i]]] < i)
            xtree.update(cc[A[i]], i);

    L = vector<int>(N);
    for (int i=0; i<N; i++) {
        int diff = xtree.query(0, cc[A[i]]);
        L[i] = (diff == -INT_MAX) ? N : (i+N) - diff;
        if (xtree.tree[M+cc[A[i]]] < i+N)
            xtree.update(cc[A[i]], i+N);
    }
}

void solve() {
    cin >> N;

    A = vector<int>(N);
    for (int& i : A)
        cin >> i;
    compute_bounds();

    vector<long long> so_diff(N, 0);
    for (int i=0; i<N; i++) {
        so_diff[0] += A[i];
        if (R[i] < N)
            so_diff[R[i]] -= A[i];

        if (L[i] < N)
            so_diff[L[i]] -= A[i];
        if (R[i] + L[i] < N)
            so_diff[R[i]+L[i]] += A[i];
    }

    vector<long long> fo_diff(N, 0);
    fo_diff[0] = so_diff[0];
    for (int i=1; i<N; i++)
        fo_diff[i] = fo_diff[i-1] + so_diff[i];

    vector<long long> ans(N, 0);
    ans[0] = fo_diff[0];
    for (int i=1; i<N; i++)
        ans[i] = ans[i-1] + fo_diff[i];

    for (int i=1; i<N; i++)
        cout << ans[i] << endl;
    cout << ans[N-1] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
