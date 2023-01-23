#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e5+5;
void solve(){
    int n, m; cin >> n >> m;
    vector<int> adj_list[n];

    for (int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
    }

    vector<long long> d(n, 0);
    vector<bool> visited(n, 0);
    queue<int> q;

    d[0] = 0; q.push(0);
    visited[0] = true;
    while (!q.empty()){
        int x = q.front(); q.pop();

        for (auto u : adj_list[x]){
            if (!visited[u]){
                visited[u] = true;
                d[u] = d[x]+1;
                q.push(u);
            }
        }
    }

    vector<int> dp[2];
    dp[0] = vector<int>(n, MX);
    dp[1] = vector<int>(n, MX);

    for (int i=0; i<n; i++){
        dp[0][i] = d[i];
    }

    for (int i=0; i<n; i++){
        for (int u : adj_list[i]){
            if (d[i] < d[u])
                dp[0][i] = min(dp[0][i], dp[0][u]);
        }
    }
    for (int i=0; i<n; i++){
        for (int u : adj_list[i]){
            if (d[i] >= d[u])
                dp[1][i] = min(dp[1][i], dp[0][u]);
        }
    }
    for (int i=0; i<n; i++){
        for (int u : adj_list[i]){
            if (d[i] < d[u]){
                dp[1][i] = min(dp[1][i], dp[1][u]);
            }
        }
    }

    /* cout << dp[0] << endl; */
    /* cout << dp[1] << endl; */
    /* cout << "____" << endl; */

    for (int i=0; i<n; i++){
        cout << min(dp[0][i], dp[1][i]) << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
