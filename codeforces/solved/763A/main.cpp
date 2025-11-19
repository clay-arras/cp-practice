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

const int MX = 1e5+5;
vector<int> adj_list[MX];

void solve() {
    int N; cin >> N;

    vector<pair<int, int>> e;
    for (int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        e.push_back({u, v});
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> c(N);
    for (int& i : c)
        cin >> i;

    DSU d; d.init(N);
    int grps = N;
    for (auto ed : e) {
        if (c[ed.first] == c[ed.second])
            grps -= d.unite(ed.first, ed.second);
    }

    for (int i=0; i<N; i++) {
        int sum = 1;
        int rtc = d.get(i);
        for (int j : adj_list[i])
            sum += (d.get(j) != rtc);

        if (grps == sum) {
            cout << "YES" << endl;
            cout << (i+1) << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
