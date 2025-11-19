#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// Find the graph that minimizes the path between any two vertices


int N, M;
struct Road { int u, v, l, c; };
bool operator<(const Road& x, const Road& y) { return x.c < y.c; }
vector<Road> e;

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
    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int u, v, l, c; cin >> u >> v >> l >> c;
        --u, --v;
        e.push_back({u, v, l, c});
    }
    sort(e.begin(), e.end());

    DSU D; D.init(N+1);
    long long ans = 0;
    for (auto &a : e) {
        if (D.unite(a.u, a.v)) {
            ans += a.c;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

