#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
	vector<long long> e;
    void init(long long N) {
        e = vector<long long>(N,-1);
    }
	long long get(long long x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }
	long long size(long long x) {
        return -e[get(x)];
    }
	bool unite(long long x, long long y) {
		x = get(x), y = get(y);
        if (x == y)
            return 0;
		if (e[x] > e[y])
            swap(x,y);
		e[x] += e[y];
        e[y] = x;
        return 1;
	}
};

template<class T> T
Kruskals (long long N, vector<pair<T, pair<long long, long long>>> e) {
    sort(e.begin(), e.end());
    DSU D; D.init(N+1);
    T ans = 0;

    for (auto &a : e) {
        if (D.unite(a.second.first, a.second.second))
            ans += a.first;
    }
    return ans;
}

void solve() {
    long long A, B; cin >> A >> B;
    long long N, M; cin >> N >> M;

    vector<long long> nFence(N), mFence(M);
    for (long long &t : nFence)
        cin >> t;
    for (long long &t : mFence)
        cin >> t;

    nFence.push_back(A);
    mFence.push_back(B);
    nFence.push_back(0);
    mFence.push_back(0);

    sort(nFence.begin(), nFence.end());
    sort(mFence.begin(), mFence.end());

    vector<pair<long long, pair<long long, long long>>> e;
    N += 2, M += 2;
	long long cur_sect = 0;
	for (long long row=1; row<M; row++, cur_sect++){
		for (long long i=0; i<N-2; i++, cur_sect++)
            e.push_back({mFence[row] - mFence[row-1], {cur_sect, cur_sect+1}});
	}

	cur_sect = N - 1;
	for (long long col=1; col<N; col++) {
		long long init = cur_sect;
		for (long long i=0; i<M-2; i++, cur_sect += (N-1))
            e.push_back({nFence[col] - nFence[col-1], {cur_sect-(N-1), cur_sect}});
		cur_sect = init + 1;
	}

    long long T = (N+2)*(M+2);
    long long ans = Kruskals(T, e);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}
