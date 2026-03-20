#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MOD = 998244353;
const int MX = 2e5+1;
vector<int> adj_list[MX];

void solve() { 
    int N, M; cin >> N >> M;
    vector<long long> A(N);
    for (long long& i : A)
        cin >> i;

    for (int i=0; i<M; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[v].push_back(u);
    }
    
    vector<pair<long long, int>> P;
    for (int i=0; i<N; i++) 
        P.push_back({A[i], i});
    sort(P.begin(), P.end());

    vector<unordered_map<int, long long>> ways(N);
    long long ans = 0;
    for (int i=0; i<N; i++) {
        auto [a, x] = P[i];
        for (int j : adj_list[x]) {
            if (ways[j].count(A[x] - A[j]))
                ways[x][A[j]] = (ways[x][A[j]] + ways[j][A[x]-A[j]] + 1LL) % MOD;
            else 
                ways[x][A[j]] = (ways[x][A[j]] + 1LL) % MOD;
        }
        for (auto [k, v] : ways[x])
            ans = (ans + v) % MOD;
    }

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

/*
for each element, need to add the number of children PLUS for each children,
need to sum the previous number in the cycle

ways[i][A[j]] += ways[j][A[i] - A[j]]] + 1

*/
