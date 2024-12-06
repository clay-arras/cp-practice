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
    T f(T a, T b) { return a ^ b; }

    vector<T> tree; int n;
    SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}

    void update(int pos, T val) {
        for (tree[pos += n] = val; pos /= 2;)
            tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, tree[b++]);
            if (e % 2) rb = f(tree[--e], rb);
        }
        return f(ra, rb);
    }
};

const int MAXN = 1e5+5;
int n, arr[MAXN], in[MAXN], ot[MAXN], par[MAXN][22];
vector<int> adj[MAXN];
int timer = 1;

void dfs(int v = 0, int p = 0) {
	in[v] = timer++;
	par[v][0] = p;
	for (int i=1; i<22; i++) par[v][i] = par[par[v][i - 1]][i - 1];
	for (int x : adj[v]) {
		if (x == p) continue;
		dfs(x, v);
	}
	ot[v] = timer++;
}
bool anc(int u, int v) {
    return (in[u] <= in[v] && ot[u] >= ot[v]);
}
int lca(int u, int v) {
	if (anc(u, v)) return u;
	for (int i=21; i>=0; i--) {
		if (par[u][i] >= 0 && !anc(par[u][i], v)) u = par[u][i];
	}
	return par[u][0];
}

int main() {
	freopen("cowland.in", "r", stdin);
	freopen("cowland.out", "w", stdout);

	int q;
	cin >> n >> q;
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();

    SegTree<int> T(n+1);
	for (int i=0; i<n; i++) {
		T.update(in[i], arr[i]);
		T.update(ot[i], arr[i]);
	}

	for (int que=0; que<q; que++) {
		int t;
		cin >> t;
		if (t == 1) {
			int s, x; cin >> s >> x;
			--s;
			T.update(in[s], arr[s]);
			T.update(ot[s], arr[s]);
			arr[s] = x;
			T.update(in[s], arr[s]);
			T.update(ot[s], arr[s]);
		} else {
			int u, v; cin >> u >> v;
			--u, --v;
			int w = lca(u, v);
			cout << ((T.query(0, in[u]) ^ T.query(0, in[v])) ^ arr[w]) << endl;
		}
	}
}
