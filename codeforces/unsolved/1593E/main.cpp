#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> p;

int K;
int cnt;

pair<int, int> dfs1(int s, int depth) {
    visited[s] = true;

    pair<int, int> ret = {depth, s};
    for (int i : adj_list[s]) {
        if (!visited[i])
            ret = max(ret, dfs1(i, depth+1));
    }
    return ret;
}

bool dfs2(int s, int ed) {
    visited[s] = true;
    if (s == ed) {
        p.push_back(s);
        return true;
    }

    bool ok = false;
    for (int i : adj_list[s]) {
        if (!visited[i])
            ok |= dfs2(i, ed);
    }
    if (ok) p.push_back(s);
    return ok;
}

int dfs3(int s) {
    visited[s] = true;

    int mx = -1;
    for (int i : adj_list[s]) {
        if (!visited[i])
            mx = max(mx, dfs3(i));
    }
    int val = mx == -1 ? 1 : mx + 1;
    cnt += (val > K);
    return val;
}

void solve() {
    int N, k; cin >> N >> k;

    K = k;
    adj_list = vector<vector<int>>(N);
    for (int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    visited = vector<bool> (N, false);
    auto st = dfs1(0, 0).second;
    visited = vector<bool> (N, false);
    auto ed = dfs1(st, 0).second;

    visited = vector<bool> (N, false);
    dfs2(st, ed);
    double plen = (int)p.size()-1;
    pair<int, int> md = {p[floor(plen/2)], p[ceil(plen/2)]};

    visited = vector<bool> (N, false);
    visited[md.second] = true;
    dfs3(md.first);
    visited[md.second] = false;
    dfs3(md.second);

    cout << cnt << endl;

    p.clear();
    cnt = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
