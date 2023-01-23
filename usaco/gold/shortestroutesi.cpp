#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e5+5;
const long long mxV = LLONG_MAX-9e2;
vector<pair<int, int>> adj_list[MX];
void solve(){
    int n, m; cin >> n >> m;

    while (m--){
        long long u, v, w; cin >> u >> v >> w;
        --u, --v;
        adj_list[u].push_back({w, v});
    }

    vector<long long> d(n, mxV);
    vector<bool> visited(n, 0);
    priority_queue<pair<long long, long long>> q;

    d[0] = 0;
    q.push({0, 0});
    while (!q.empty()){
        int x = q.top().second; q.pop();
        if (visited[x]) continue;
        visited[x] = true;

        for (auto u : adj_list[x]){
            long long w = u.first, v = u.second;
            if (d[v] > d[x] + w){
                d[v] = d[x] + w;
                q.push({-d[v], v});
            }
        }
    }
    for (long long i : d)
        cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
