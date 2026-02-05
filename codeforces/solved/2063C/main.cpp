#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e5+7;
vector<vector<int>> adj_list;
vector<bool> visited;
unordered_set<int> rem;

void dfs(int x) {
    if (rem.count(x)) return;
    visited[x] = true;

    for (int i : adj_list[x])
        if (!visited[i])
            dfs(i);
}

void solve() {
    int N; cin >> N;

    adj_list = vector<vector<int>>(N);
    visited = vector<bool>(N, false);
    vector<int> deg(N, 1), mxN(N, 0);
    for (int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        deg[u]++;
        deg[v]++;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    if (N <= 2) {
        cout << 0 << endl;
        return;
    }

    int mxD = *max_element(deg.begin(), deg.end());
    for (int i=0; i<N; i++) {
        for (int t : adj_list[i])
            mxN[i] += (deg[t] == mxD);
    }

    vector<int> ord(N);

    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        if (deg[a] == deg[b])
            return mxN[a] < mxN[b];
        return deg[a] > deg[b];
    });
    rem.insert(ord[0]);

    for (int i=0; i<N; i++) {
        if (i == ord[0]) {
            deg[i] = 0;
            continue;
        }
        for (int t : adj_list[i])
            deg[i] -= (t == ord[0]);
    }

    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return deg[a] > deg[b];
    });
    rem.insert(ord[0]);

    int cc = 0;
    for (int i=0; i<N; i++) {
        if (!visited[i] && !rem.count(i)) {
            ++cc;
            dfs(i);
        }
    }

    cout << cc << endl;

    rem.clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

