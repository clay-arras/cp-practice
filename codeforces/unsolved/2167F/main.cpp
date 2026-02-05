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

void solve() {
    cin >> N >> K;
    for (int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }


    

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
