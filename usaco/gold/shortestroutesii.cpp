#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MX = LLONG_MAX-9;
void solve(){
    int n, m, q; cin >> n >> m >> q;

    vector<vector<long long>> d (n, vector<long long> (n, MX));
    for (int i=0; i<m; i++){
        long long u, v, w; cin >> u >> v >> w;
        --u, --v;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for (int k=0; k<n; ++k){
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if (d[i][k] < MX and d[k][j] < MX)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while (q--){
        long long a, b; cin >> a >> b;
        --a, --b;
        if (a == b) cout << 0 << endl;
        else cout << (d[a][b] == MX ? -1 : d[a][b]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
