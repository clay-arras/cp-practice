#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif


const int MX = 1e3+3;
const int mxV = 1e7+5;
const long long prec = 1e6;

struct Edge {int v, c, f;};
vector<Edge> adj_list[MX];

int n;

long Dijkstras(int flowMin){
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
            int c = u.c, v = u.v, f = u.f;
            if (f < flowMin)
                continue;

            if (d[v] > d[x] + c){
                d[v] = d[x] + c;
                q.push({-d[v], v});
            }
        }
    }
    return d[n-1];
}

void solve(){
    int m; cin >> n >> m;

    vector<int> fl;
    for (int i=0; i<m; i++){
        int a, b, c, f; cin >> a >> b >> c >> f;
        --a, --b;
        adj_list[a].push_back({b, c, f});
        adj_list[b].push_back({a, c, f});

        fl.push_back(f);
    }

    long ans = -1;
    for (int f : fl){
        int c = Dijkstras(f);
        if (c == mxV)
            continue;

        long val = f*1.0/c*prec*1LL;
        ans = max(ans, val);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
