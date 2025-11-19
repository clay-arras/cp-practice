#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MX = 2e5+5;
vector<long long> adj_list[MX];

template<class T>
struct SegTree {
	static constexpr T unit = {MX, -1};
	T f(T a, T b) { return min(a, b); }

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

void solve(){
    long long N, M; cin >> N >> M;

    for (long long i=0; i<M; i++){
        long long u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<long long> d(N);
    for (long long i=0; i<N; i++){
        d[i] = (long long)adj_list[i].size();
    }

    SegTree<pair<long long, long long>> T(N, {MX, -1});
    for (long long i=0; i<N; i++){
        T.update(i, {d[i], i});
    }

    long long ans = 0;
    for (long long i=0; i<N; i++){
        pair<long long, long long> minV = T.query(0, N);

        long long inx = minV.second;
        ans = max(ans, (N-i)*minV.first);

        for (long long j : adj_list[inx])
            T.update(j, {T.tree[j+N].first-1, j});
        T.update(inx, {MX, inx});
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}

