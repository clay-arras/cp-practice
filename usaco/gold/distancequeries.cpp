#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

/* struct LCA { */
const long long MX = 1e7;
vector<long long> adj_list[MX];
long long tin[MX], euler_tour[MX], segtree[MX], depth[MX];
long long timer = 0;

void dfs(int node=0, int parent=-1, int d=0) {
    tin[node] = timer;
    euler_tour[timer++] = node;
    depth[node] = d;
    for (int i : adj_list[node]) {
        if (i != parent) {
            dfs(i, node, d+1);
            euler_tour[timer++] = node;
        }
    }
}
int mn_tin (int x, int y) {
    if (x == -1)
        return y;
    if (y == -1)
        return x;
    return (tin[x] < tin[y] ? x : y);
}
void build (int node=1, int l=0, int r=timer-1) {
    if (l == r) segtree[node] = euler_tour[l];
    else {
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        segtree[node] = mn_tin(segtree[node * 2], segtree[node * 2 + 1]);
    }
}
int query (int a, int b, int node=1, int l=0, int r=timer-1) {
    if (l > b or r < a)
        return -1;
    if (l >= a and r <= b)
        return segtree[node];
    int mid = (l + r) / 2;
    return mn_tin(query(a, b, node*2, l, mid), query(a, b, node*2+1, mid+1, r));
}
int lca (int a, int b) {
    if (tin[a] > tin[b])
        swap(a, b);
    return query(tin[a], tin[b]);
}
/* }; */

void solve() {
    int N, Q; cin >> N >> Q;

    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    dfs();
    build();
    while (Q--) {
        long long a, b; cin >> a >> b;
        --a, --b;

        long long c=lca(a, b);
        cout << depth[a] + depth[b] - 2*depth[c] << endl;
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

