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

const int MX = 2e3+4;
vector<pair<int, int>> adj_list[MX];
int grid[MX][MX];

template<class T> T
Kruskals (int N, vector<pair<T, pair<int, int>>> e) {
    sort(e.begin(), e.end());
    DSU D; D.init(N+1);
    T ans = 0;
    for (auto &a : e) {
        if (D.unite(a.second.first, a.second.second)) {
            adj_list[a.second.first].push_back({a.second.second, a.first});
            adj_list[a.second.second].push_back({a.second.first, a.first});
            ans += a.first;
        }
    }
    return ans;
}

bool DFS(int curr, int prev, int src, int dist) {
    if (grid[src][curr] != dist or (src != curr and grid[src][curr] == 0)) return false;
    bool ans = true;
    for (auto u : adj_list[curr]) {
        if (u.first != prev)
            ans &= DFS(u.first, curr, src, dist+u.second);
    }
    return ans;
}

void solve() {
    int N; cin >> N;

    bool ans = true;
    vector<pair<int, pair<int, int>>> e;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> grid[i][j];
            if (i != j) {
                if (j < i and grid[i][j] != grid[j][i]) ans &= false;
                if (i < j) e.push_back({grid[i][j], {i, j}});
            } else ans &= (grid[i][j] == 0);
        }
    }
    Kruskals(N, e);
    for (int i=0; i<N; i++)
        ans &= DFS(i, -1, i, 0);
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*



*/
