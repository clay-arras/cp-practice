#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX=20, MOD=1e9+7;
vector<int> adj_list[MX];
void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// dp[1][2][3][..] where 1 is when we visit the first city, etc
// dp[which iteration we are on][which node we are on][bitmask position]
