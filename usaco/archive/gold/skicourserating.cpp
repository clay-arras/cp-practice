#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct Edge{ long long u, v, w; };
bool operator<(const Edge& x, const Edge& y) { return x.w < y.w; }

// Vim capital p
vector<long long> h;
vector<long long> stp;

long long sum;
int N, M, T;
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

	bool unite(int x, int y, int w) {
		x = get(x), y = get(y);
        if (x == y)
            return 0;

		if (e[x] > e[y])
            swap(x,y);

        if (size(x) + size(y) >= T) {
            sum += w * (stp[x] + stp[y]);
            stp[x] = 0;
            stp[y] = 0;
        }
        stp[x] += stp[y];

		e[x] += e[y];
        e[y] = x;

        return 1;
	}
};
void solve() {
    cin >> N >> M >> T;

    h.resize(N*M); stp.resize(N*M);
    for (int i=0; i<N*M; i++)
        cin >> h[i];
    for (int i=0; i<N*M; i++)
        cin >> stp[i];

    vector<Edge> e;
    DSU d; d.init(N*M);
    for (int i=0; i<N*M; i++) {
        if (i % M != 0)
            e.push_back({i, i-1, abs(h[i] - h[i-1])});
        if (i >= M)
            e.push_back({i, i-M, abs(h[i] - h[i-M])});
    }
    sort(e.begin(), e.end());

    for (int i=0; i<(int)e.size(); i++) {
        auto val = e[i];
        d.unite(val.u, val.v, val.w);
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

// Same algorithm for Tractor.cpp but modified a little. Might be way to slow, find a way to speed  it up
