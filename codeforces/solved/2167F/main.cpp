#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e5+1;
vector<int> adj_list[MX];
vector<bool> visited;
int N, K; 
vector<int> A;
long long ans, cnt;

int dfs0(int x) {
    visited[x] = true;
    int ret = 1;
    for (int i : adj_list[x]) {
        if (!visited[i])
            ret += dfs0(i);
    }
    return A[x] = ret;
}

void dfs1(int x, int prev) {
    visited[x] = true; 

    int a = A[x], b = A[prev];
    int pc = cnt;
    if (prev != -1) {
        A[x] = N;
        A[prev] = b - a;
        cnt -= (a >= K) - (A[x] >= K);
        cnt -= (b >= K) - (A[prev] >= K);
    }
    ans += cnt;

    for (int i : adj_list[x]) {
        if (!visited[i])
            dfs1(i, x);
    }

    if (prev != -1) {
        A[x] = a;
        A[prev] = b;
        cnt = pc;
    }
}

void solve() {
    cin >> N >> K;
    for (int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    A = vector<int>(N, 0);
    visited = vector<bool>(N, false);
    dfs0(0);

    cnt = 0;
    for (int i : A)
        cnt += (i >= K);
    ans = 0;

    visited = vector<bool>(N, false);
    dfs1(0, -1);
    cout << ans << endl;

    fill(adj_list, adj_list+N, vector<int>{});
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
