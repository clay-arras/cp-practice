#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e6+5;
vector<int> adj_list[MX];

// Learned: use the DSU with boolean merge
// Reverse input sometimes helps: DSU is only good at adding and finding, not removing
// Consider before merging if there are any prerequisites that must be found
// Check the algorithm beforehand
struct DSU{
    vector<int> e, h;
    DSU(int N){
        for (int i=0; i<N; i++){
            e.push_back(i);
            h.push_back(0);
        }
    }

    int find(int s){
        if (s != e[s])
            s = find(e[s]);
        return e[s];
    }

    bool merge(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB)
            return false;

        if (h[rootA] > h[rootB]) {
            e[rootB] = rootA;
            h[rootA] = max(h[rootA], h[rootB] + 1);
        } else {
            e[rootA] = rootB;
            h[rootB] = max(h[rootB], h[rootA] + 1);
        }
        return true;

    }
};

void solve(){
    int N, M; cin >> N >> M;

    while (M--){
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> o;
    for (int i=0; i<N; i++){
        int t; cin >> t;
        --t;
        o.push_back(t);
    }
    reverse(o.begin(), o.end());
    // Start with a completely closed farm
    // Count the number of connected components

    DSU d(N);
    vector<string> ans = {"YES"};
    vector<bool> op(N, false);
    int cc = 1;

    op[o[0]] = true;
    for (int i=1; i<N; i++){
        // Take input
        // Open up the o[i]th farm

        cc++;
        op[o[i]] = true;
        for (int u : adj_list[o[i]]){
            if (op[u])
                if (d.merge(u, o[i]))
                    cc--;
        }
        /* cout << cc << endl; */
        ans.push_back((cc == 1 ? "YES" : "NO"));
    }
    for (int i=N-1; i>=0; i--)
        cout << ans[i] << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
