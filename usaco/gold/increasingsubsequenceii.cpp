#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MOD = 1e9+7;

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
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, tree[b++]) % MOD;
			if (e % 2) rb = f(tree[--e], rb) % MOD;
		}
		return f(ra, rb) % MOD;
	}
};

bool comp(pair<int, int> p, pair<int, int> q) { return p.second < q.second; }

void solve() {
    int N; cin >> N;

    vector<pair<int, int>> A(N);
    for(int i=0; i<N; i++) {
        int t; cin >> t;
        A[i] = {t, i};
    }

    map<int, int> m;
    sort(A.begin(), A.end());
    for (int i=0, it=0; i<N; i++) {
        if (m[A[i].first] == 0) {
            m[A[i].first] = ++it;
        }
        A[i].first = it;
    }
    sort(A.begin(), A.end(), comp);

    SegTree<long long> T(N+2);
    for (int i=0; i<N; i++) {
        long long nVal = T.query(0, A[i].first + 1) % MOD;
        T.update(A[i].first, nVal + 1);
    }

    long long ans = T.query(0, N + 1) % MOD;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}


