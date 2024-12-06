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
    sort(e.rbegin(), e.rend());
    DSU D; D.init(N+1);
    T ans = 0;

    for (auto &a : e) {
        if (D.unite(a.second.first, a.second.second))
            ans += a.first;
    }
    return ans;
}

void solve() {
    int N; cin >> N;

    vector<long long> ids;
    for (int i=0; i<N; i++) {
        long long t; cin >> t;
        ids.push_back(t);
    }

    vector<pair<long long, pair<int, int>>> e;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            e.push_back({ids[i]^ids[j], {i, j}});
        }
    }
    cout << Kruskals(N, e) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}
