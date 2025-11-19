#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

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

int N;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void solve(){
    cin >> N;
    vector<vector<int>> g(N, vector<int>(N, -1));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> g[i][j];
    }

    vector<Edge> e;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {

            for (int k=0; k<4; k++){
                int x = i + dx[k], y = j + dy[k];

                if (x >= 0 and x < N and y >= 0 and y < N){
                    int diff = abs(g[i][j] - g[x][y]);
                    int ij = i*N + j;
                    int xy = x*N + y;

                    e.push_back({xy, ij, diff});
                }
            }
        }
    }
    sort(e.begin(), e.end());
    DSU d; d.init(N*N);

    int IS_BIG = (N*N+1)/2;
    for (int i=0; i<(int)e.size(); i++){
        Edge E = e[i];
        d.unite(E.u, E.v);

        if (d.size(E.u) >= IS_BIG){
            cout << E.w << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
