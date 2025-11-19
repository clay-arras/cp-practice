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

void solve() {
    int N, Q; cin >> N >> Q;

    vector<pair<int, pair<int, int>>> edges;
    for (int i=0; i<N-1; i++) {
        int p, q, r; cin >> p >> q >> r;
        --p, --q;
        edges.push_back({r, {p, q}});
    }
    sort(edges.rbegin(), edges.rend());

    vector<pair<pair<int, int>, int>> queries;
    for (int i=0; i<Q; i++) {
        int k, v; cin >> k >> v;
        --v;
        queries.push_back({{k, v}, i});
    }
    sort(queries.rbegin(), queries.rend());

    vector<int> ans(Q);
    DSU d; d.init(N);
    int j = 0;
    for (auto [q, i] : queries) {
        int k = q.first, v = q.second;
        for (; j<N-1 && edges[j].first>=k; j++)
            d.unite(edges[j].second.first, edges[j].second.second);
        ans[i] = d.size(v) - 1;
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
