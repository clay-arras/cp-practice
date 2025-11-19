#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e5+5;
const long long mxV = 1e18;
vector<pair<long long, long long>> adj_listF[MX];
vector<pair<long long, long long>> adj_listL[MX];

// Algorithm: run Dijkstras on 0 and N, and for each N check the max

struct Edge{ long long u, v, w; };

void solve(){
    int n, m; cin >> n >> m;

    vector<Edge> e;
    for (int i=0; i<m; i++){
        long long u, v, w; cin >> u >> v >> w;
        --u, --v;
        adj_listF[u].push_back({w, v});
        adj_listL[v].push_back({w, u});
        e.push_back({u, v, w});
    }

    vector<long long> df(n, mxV);
    vector<bool> visited(n, 0);
    priority_queue<pair<long long, long long>> q;


    df[0] = 0;
    q.push({0, 0});
    while (!q.empty()){
        long long u = q.top().second; q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto x : adj_listF[u]){
            long long w = x.first, v = x.second;
            if (df[v] > df[u] + w){
                df[v] = df[u] + w;
                q.push({-df[v], v});
            }
        }
    }
    fill(visited.begin(), visited.end(), 0);
    vector<long long> dl(n, mxV);

    dl[n-1] = 0;
    q.push({0, n-1});
    while (!q.empty()){
        long long u = q.top().second; q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto x : adj_listL[u]){
            long long w = x.first, v = x.second;
            if (dl[v] > dl[u] + w){
                dl[v] = dl[u] + w;
                q.push({-dl[v], v});
            }
        }
    }

    long long ans = mxV;
    for (int i=0; i<m; i++){
        Edge ed = e[i];
        ans = min(ans, df[ed.u] + (int)floor(ed.w*1.0/2) + dl[ed.v]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
