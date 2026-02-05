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
        e++;
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, tree[b++]);
            if (e % 2) rb = f(tree[--e], rb);
        }
        return f(ra, rb);
    }
};

struct PairHash {
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

int N, M;
vector<int> L, R, K;
unordered_map<int, int> cc;
vector<int> ans;

void solve_1s() { // for all js where L[j] > L[i] and R[j] > R[i]
    SegTree<int> stree(M, 0);

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if (R[i] == R[j])
            return L[i] < L[j];
        return R[i] > R[j];
    });

    for (int it=0; it<N; it++) {
        int i = idx[it];
        ans[i] += stree.query(cc[L[i]]+1, cc[R[i] - K[i]]);
        stree.update(cc[L[i]], stree.tree[M + cc[L[i]]] + 1);
    }
}


void solve_1e() { // for all js where L[j] < L[i] and R[j] < R[i]
    SegTree<int> stree(M, 0);

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if (L[i] == L[j])
            return R[i] > R[j];
        return L[i] < L[j];
    });

    for (int it=0; it<N; it++) {
        int i = idx[it];
        ans[i] += stree.query(cc[L[i] + K[i]], cc[R[i]]-1);
        stree.update(cc[R[i]], stree.tree[M + cc[R[i]]] + 1);
    }
}

vector<int> outers() {
    vector<int> ans_o(N);
    SegTree<int> stree(M, 0);

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if (L[i] == L[j])
            return R[i] < R[j];
        return L[i] < L[j];
    });

    for (int it=0; it<N; it++) {
        int i = idx[it];
        ans_o[i] = stree.query(cc[R[i]]+1, M-1); // strictly greater
        stree.update(cc[R[i]], stree.tree[M + cc[R[i]]] + 1);
    }

    return ans_o;
}

void solve_2i() { // for all js where L[j] > L[i] and R[j] < R[i]
    SegTree<int> stree(M, 0), etree(M, 0);

    vector<pair<int, int>> idx;
    for (int i=0; i<N; i++) {
        idx.push_back({K[i], -(i+1)}); // we want to add before query if equal
        idx.push_back({R[i] - L[i], i});
    }
    sort(idx.rbegin(), idx.rend());
    vector<int> ots = outers();

    int ni = 0;
    for (auto [rg, idx] : idx) {
        if (idx < 0) { // query
            int i = -idx - 1;
            ans[i] += ni - stree.query(0, cc[L[i]]-1) - etree.query(cc[R[i]]+1, M-1)-1 + ots[i];
        } else { // add
            int i = idx;
            stree.update(cc[L[i]], stree.tree[M + cc[L[i]]] + 1);
            etree.update(cc[R[i]], etree.tree[M + cc[R[i]]] + 1);
            ++ni;
        }
    }
}

void solve_2o() { // for all js where L[j] <= L[i] and R[j] >= R[i]
    SegTree<int> stree(M, 0);

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if (L[i] == L[j])
            return R[i] > R[j];
        return L[i] < L[j];
    });
    unordered_map<pair<int, int>, vector<int>, PairHash> m;
    for (int i=0; i<N; i++)
        m[{L[i], R[i]}].push_back(i);

    for (int it=0; it<N; it++) {
        int i = idx[it];
        for (auto id : m[{L[i], R[i]}]) 
            ans[id] += stree.query(cc[R[i]], M-1); // strictly greater, to avoid overcounting with 2i
        for (auto id : m[{L[i], R[i]}]) 
            stree.update(cc[R[id]], stree.tree[M + cc[R[id]]] + 1);
        m[{L[i], R[i]}] = {};
    }
}

void solve() {
    cin >> N;

    L = vector<int>(N);
    R = vector<int>(N);
    K = vector<int>(N);
    ans = vector<int> (N, 0);
    for (int i=0; i<N; i++)
        cin >> L[i] >> R[i] >> K[i];

    set<int> s;
    for (int i=0; i<N; i++) {
        s.insert(L[i]);
        s.insert(R[i]);
        s.insert(L[i] + K[i]);
        s.insert(R[i] - K[i]);
    }
    M = 0;
    for (int i : s)
        cc[i] = M++;

    solve_1s();
    solve_1e();
    solve_2i();
    solve_2o();

    for (int i=0; i<N; i++)
        cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}

