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

const int MX = 1e5+1;
vector<int> adj_list[MX];

void solve() {
    int N, M; cin >> N >> M;

    vector<pair<int, int>> e;
    for (int i=0; i<M; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        e.push_back({u, v});
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    multiset<pair<int, int>> fd;
    unordered_map<int, decltype(fd.begin())> m;
    for (int i=0; i<N; i++)
        m[i] = fd.insert({(int)adj_list[i].size(), i});

    vector<pair<int, pair<int, int>>> eord;
    for (int k=0; k<N; k++) {
        auto prev = fd.begin();
        int i = prev->second; 
        int f = prev->first;

        for (int t : adj_list[i]) {
            if (m.count(t)) {
                auto it = m[t];
                m[t] = fd.insert({it->first - 1, t});
                eord.push_back({f, {i, t}});

                fd.erase(it);
            }
        }
        fd.erase(prev);
        m.erase(i);
    }
    reverse(eord.rbegin(), eord.rend());
    DSU d; d.init(N);

    int ans = 0;
    for (auto [mn, e] : eord) {
        d.unite(e.first, e.second);
        ans = max(ans, d.size(e.first) * mn);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
