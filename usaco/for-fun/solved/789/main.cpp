#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
    vector<int> e;
    void init(int N) {
        e = vector<int>(N,-1);
    }
    int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }
    int size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x,y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};


struct MergeTree {
    vector<int> tree, size, minK;
    int N;

    void init(int N) {
        tree = vector<int> (N, -1);
        size = vector<int> (N, 1);
        minK = vector<int> (N, INT_MAX);
        this->N = N;
    }

    void constr(vector<pair<int, pair<int, int>>>& edges) {
        sort(edges.rbegin(), edges.rend());
        DSU currL; currL.init(2*N);

        int cnt = N;
        for (auto [r, e] : edges) {
            int ul = currL.get(e.first);
            int vl = currL.get(e.second);

            tree.push_back(cnt); 
            minK.push_back(r);
            size.push_back(size[ul] + size[vl]);

            tree[ul] = cnt;
            tree[vl] = cnt;

            currL.e[ul] = cnt;
            currL.e[vl] = cnt;
            ++cnt;
        }
    }

    int query(int k, int v) {
        int lv = get(k, v);
        if (minK[lv] >= k) 
            return size[lv] - 1;
        return 0;
    }

    int get(int k, int v) {
        if (tree[v] == v || minK[tree[v]] < k) 
            return v;
        return tree[v] = get(k, tree[v]);
    }
};

void solve() {
    int N, Q; cin >> N >> Q;

    vector<pair<int, pair<int, int>>> edges;
    for (int i=0; i<N-1; i++) {
        int p, q, r; cin >> p >> q >> r;
        --p, --q;
        edges.push_back({r, {p, q}});
    }

    vector<pair<pair<int, int>, int>> queries;
    for (int i=0; i<Q; i++) {
        int k, v; cin >> k >> v;
        --v;
        queries.push_back({{k, v}, i});
    }
    sort(queries.rbegin(), queries.rend());

    MergeTree mt; 
    mt.init(N);
    mt.constr(edges);

    vector<int> ans(Q);
    for (auto [q, i] : queries) {
        int k = q.first, v = q.second;
        ans[i] = mt.query(k, v);
    }

    for (int i : ans)
        cout << i << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
