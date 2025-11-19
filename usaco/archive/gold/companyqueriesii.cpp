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
int n;
vector<long long> graph[MX];
long long tin[MX], euler_tour[MX], segtree[MX];
long long timer = 0;

void dfs(int node=0, int parent=-1) {
    tin[node] = timer;
    euler_tour[timer++] = node;
    for (int i : graph[node]) {
        if (i != parent) {
            dfs(i, node);
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

    for (int i=1; i<N; i++) {
        int t; cin >> t;
        --t;
        graph[i].push_back(t);
        graph[t].push_back(i);
    }
    dfs();
    build();

    while (Q--) {
        int a, b; cin >> a >> b;
        --a, --b;
        cout << lca(a, b)+1 << endl;
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
