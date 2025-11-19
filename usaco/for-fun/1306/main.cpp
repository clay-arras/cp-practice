#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
struct SegTree {
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }
    vector<T> tree; int n;
    SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}
    void update(int pos, T val) {
        for (tree[pos += n] = val; pos /= 2;)
            tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
    }
    T query(int b, int e) {
        e++;
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, tree[b++]);
            if (e % 2) rb = f(tree[--e], rb);
        }
        return f(ra, rb);
    }
};

const int MX = 2e5+9;
vector<int> adj_list[MX];
bool visited[MX];

int timer = 0, st[MX], en[MX];
void dfs1(int node, int parent) {
    st[node] = timer++;
    for (int i : adj_list[node]) {
        if (i != parent) 
            dfs1(i, node); 
    }
    en[node] = timer - 1;
}

int N;
SegTree<long long> tree;
vector<long long> A;
void dfs2(int x, int depth=0) {
    visited[x] = true;
    tree.update(x, tree.tree[x+N] * depth);
    for (int i : adj_list[x]) 
        if (!visited[i])
            dfs2(i, depth+1);
}


long long ans = 0, np = 0;
void dfs3(int x) {
    visited[x] = true;
    
    vector<pair<int, int>> eord;
    for (int i : adj_list[x]) 
        if (!visited[i])
            eord.push_back({tree.query(st[i], en[i]), i});
    sort(eord.rbegin(), eord.rend());

    np++;
    for (long long i=0; i<(int)eord.size(); i++) {
        ans += A[eord[i].second] * np;
        dfs3(eord[i].second);
    }
    np++;
}

void solve() {
    int T; cin >> N >> T; 

    A = vector<long long>(N);
    for (int i=1; i<N; i++) {
        int p; cin >> p >> A[i];
        --p;
        adj_list[p].push_back(i);
        adj_list[i].push_back(p);
    }

    dfs1(0, -1);
    tree = SegTree<long long>(N, 0);
    for (int i=0; i<N; i++)
        tree.update(i, A[i]);

    fill(visited, visited+N, 0);
    dfs2(0);
    fill(visited, visited+N, 0);
    dfs3(0);

    cout << 2*(N-1) << " " << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
