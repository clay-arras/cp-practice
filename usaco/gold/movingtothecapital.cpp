#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e5+5;
const int mxV = 1e9+9;
bool visited[MX];
int dp[MX];
vector<int> adj_list[MX];
vector<int> d;

template<class T>
vector<T> Dijkstras(T src, int N) {
    vector<T> dist(N, mxV);
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> q;

    dist[src] = 0;
    q.push({0, src});
    while ((T)q.size()) {
        T x=q.top().first, u=q.top().second;
        q.pop();

        if (x != dist[u]) continue;
        for (auto i : adj_list[u]) {
            if (x+1 < dist[i]) {
                dist[i] = x+1;
                q.push({dist[i], i});
            }
        }
    }
    return dist;
}

void dfs(int curr) {
    visited[curr] = true;
    dp[curr] = d[curr];

    for (auto next : adj_list[curr]) {
        if (!visited[next] and d[curr] < d[next])
            dfs(next);

        if (d[curr] < d[next])
            dp[curr] = min(dp[curr], dp[next]);
        else
            dp[curr] = min(dp[curr], d[next]);
    }
}

/*

Problem: We aren't getting all the values


*/

void solve() {
    int N, M; cin >> N >> M;

    for (int i=0; i<M; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
    }
    d = Dijkstras(0, N);
    dfs(0);

    for (int i=0; i<N; i++)
        cout << dp[i] << " \n"[i == N-1];

    fill(adj_list, adj_list+N, vector<int>());
    fill(visited, visited+N, false);
    fill(dp, dp+N, mxV);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--){
        solve();
    }
}

/*

Optimize: the smallest value of d_j that we end up on
We can only strictly increase our d_i value normally
We can decrease our d_i value once

Need to dfs: the old solution didn't work because we were only going one value deep
We need to run a dfs so that we go through all the values

Run a dfs on every node => is it fast enough
Or we can run only one dfs

Process every node:
- We always visit the neighbors where d_curr < d_next

for (auto next : adj_list[curr]) {
    if (d[curr] < d[next]) {
        // Visit normally
        // The next state is dp[this][next]
        dp[this][curr] = min(dp[this][curr], dfs(next, this));
    } else if (this != 1) {
        // The next state is dp[1][next]
        dp[1][curr] = min(dp[1][curr], dfs(next, 1));
    }
}

return dp[this][curr];

OBSERVATIONS
- After the jump, there is no way to reduce the value any more




 */
