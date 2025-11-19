#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MX = 1e3+3;
vector<long long> adj_list[MX];

template<class T>
vector<T> BFS(T src, long long N) {
    const T mxV = 1e18+9;
    queue<long long> q;
    vector<T> dist(N, mxV);

    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        long long x = q.front();
        q.pop();
        for (long long t : adj_list[x]) {
            if (dist[t] == mxV) {
                dist[t] = dist[x] + 1;
                q.push(t);
            }
        }
    }
    return dist;
}

void solve() {
    long long N, E; cin >> N >> E;

    vector<pair<long long, long long>> edges;
    for (long long i=0; i<N; i++) {
        long long v, t; cin >> v >> t;
        edges.push_back({v, i});
        for (long long j=0; j<t; j++) {
            long long u; cin >> u;
            --u;
            adj_list[i].push_back(u);
        }
    }
    sort(edges.begin(), edges.end());

    long long res = 0;
    vector<long long> dp(N, 0);
    for (long long i=0; i<N; i++) {
        dp[i] = max(dp[i], edges[i].first);
        vector<long long> dist = BFS(edges[i].second, N);
        for (long long& j : dist)
            j *= E;

        for (long long j=i+1; j<N; j++)
            if (edges[j].first != edges[i].first)
                dp[j] = max(dp[j], dp[i]+edges[j].first-dist[edges[j].second]);
        res = max(res, dp[i]);
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    /* freopen("buffet.in", "r", stdin); */
    /* freopen("buffet.out", "w", stdout); */

    int t=1;
    while (t--) {
        solve();
    }
}

/*



*/
