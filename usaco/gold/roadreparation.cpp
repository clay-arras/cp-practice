#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
	vector<int> e;
    void init(int N) {
        e = vector<int>(N,-1);
    }

	int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }

	int size(int x) {
        return -e[get(x)];
    }

	bool unite(int x, int y) {
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
Kruskals (int N, vector<pair<T, pair<int, int>>> e) {
    sort(e.begin(), e.end());
    T ans = 0;
    DSU D; D.init(N+1);

    for (auto &a : e) {
        if (D.unite(a.s.f, a.s.s))
            ans += a.f;
    }
    return ans;
}

struct Edge { long long u, v, w; };
bool operator<(const Edge& x, const Edge& y) { return x.w < y.w; }

void solve() {
    int N, M; cin >> N >> M;

    vector<Edge> e;
    for (int i=0; i<M; i++) {
        long long a, b, w; cin >> a >> b >> w;
        --a, --b;
        e.push_back({a, b, w});
    }
    sort(e.begin(), e.end());

    DSU d; d.init(N);
    long long sum = 0;
    for (int i=0; i<M; i++) {
        Edge currE = e[i];
        if (d.unite(currE.u, currE.v)) {
            sum += currE.w;
        }
    }
    cout << (d.size(0) != N ? "IMPOSSIBLE" : to_string(sum)) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

