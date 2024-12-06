#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// Sort the edges by weight
// Connect each one
// If the connected components = 1, then it is solved

struct Edge{ int u, v, w; };
bool operator<(const Edge& x, const Edge& y) { return x.w < y.w; }

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

void solve(){
    int N, M; cin >> N >> M;

    vector<int> p(N);
    for (int i=0; i<N; i++){
        int t; cin >> t;
        p[i] = --t;
    }

    vector<Edge> e;
    for (int i=0; i<M; i++){
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        /* e.push_back({u, v, w}); */
    }
    sort(e.begin(), e.end());

    DSU d;
    d.init(N);

    if (is_sorted(p.begin(), p.end())){
        cout << -1 << endl;
        return;
    }

    int j=M;
    for (int i=0; i<N; i++){
        while (d.get(i) != d.get(p[i])){
            j--;
            d.unite(e[j].u, e[j].v);
        }
    }
    cout << e[j].w << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
