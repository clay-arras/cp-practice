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

	vector<T> tree; long long n;
	SegTree (long long i = 0, T def = unit) : tree(2*i, def), n(i) {}

	void update(long long pos, T val) {
		for (tree[pos += n] = val; pos /= 2;)
			tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
	}
	T query(long long b, long long e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, tree[b++]);
			if (e % 2) rb = f(tree[--e], rb);
		}
		return f(ra, rb);
	}
};

const long long MX = 2e5+5;
vector<long long> adj_list[MX];
long long timer = 0, st[MX], en[MX];

void dfs(long long s, long long prnt) {
    st[s] = timer++;
    for (long long u : adj_list[s]) {
        if (u != prnt)
            dfs(u, s);
    }
    en[s] = timer - 1;
}

void solve() {
    long long N, Q; cin >> N >> Q;

    vector<long long> V(N+1, 0);
    for (long long i=1; i<=N; i++)
        cin >> V[i];

    for (long long i=0; i<N-1; i++) {
        long long u, v; cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1, 0);
    SegTree<long long> T(N, 0);
    for (long long i=1; i<=N; i++)
        T.update(st[i], V[i]);

    for (long long i=0; i<Q; i++) {
        long long t; cin >> t;
        if (t == 1) {
            long long s, x; cin >> s >> x;
            T.update(st[s], x);
        } else {
            long long s; cin >> s;
            cout << T.query(st[s], en[s]+1) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    long long t=1;
    while (t--) {
        solve();
    }
}
