#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

long long N, M;
vector<long long> g;
vector<long long> ans;

struct DSU {
	vector<int> e;
    vector<int> mx;
    vector<vector<int>> neighbor;

    void init(int V) {
        e = vector<int>(V+2,-1);
        neighbor = vector<vector<int>>
            (V+2, vector<int>());

        mx.resize(V+2);
        for (int i=1; i<=V; i++)
            mx[i] = g[i];
        for (int i=1; i<=V; i++)
            neighbor[i].push_back(i);
    }

	int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }

	bool unite(int x, int y) {
        int val = g[x];
		x = get(x), y = get(y);
        if (x == y)
            return 0;

        if (mx[x] < mx[y])
            swap(x, y);

        e[y] = x;

        if (mx[x] > mx[y]) {
            for (auto n : neighbor[y])
                ans[n] = val;
            neighbor[y].clear();
        }

        if ((int)neighbor[x].size() < (int)neighbor[y].size())
            neighbor[x].swap(neighbor[y]);
        for (int i : neighbor[y])
            neighbor[x].push_back(i);

        neighbor[y].clear();
        mx[x] = max(mx[x], mx[y]);

        return 1;
	}
};

void solve(){
    cin >> N >> M;

    g = vector<long long>(N*M, -1);
    ans = vector<long long>(N*M, 0);
    vector<pair<int, int>> e;

    long long MX = -INT_MAX;
    for (int i=1; i<=N*M; i++) {
        long long t; cin >> t;

        g[i] = t;
        MX = max(t, MX);
        e.push_back({t, i});
    }
    sort(e.rbegin(), e.rend());

    DSU d; d.init(N*M);
    vector<bool> vis(N*M+2, false);

    for (auto V : e) {
        int pos = V.second, val = V.first;
        if (val == MX) {
            vis[pos] = true;
            continue;
        }

		if (pos % M != 1 && vis[pos-1]) d.unite(pos, pos-1);
		if (pos % M && vis[pos+1]) d.unite(pos, pos+1);
		if (pos > M && vis[pos-M]) d.unite(pos, pos-M);
		if (pos + M <= N*M && vis[pos+M]) d.unite(pos, pos+M);

		vis[pos] = true;
    }

	for (int i=1; i<=N*M; i++) {
		cout << g[i] - ans[i];
		cout << (i % M == 0 ? "\n" : " ");
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// RIGHT ALGO WRONG IMPLEMENTATION

// Go from the lowest peak
// We connect it to all the neighbors that are higher than it (all the lower nodes should have already connected)
// For each CC, we keep track of the highest value
//
// Go from the highest peak
// We connect the high peak to all the neighbors that are higher than it
// For each CC we keep track of the highest value
// Every time we join a new value to the component, then it's impossible for it to be lower...
// That means that any peak that is joined has to be the lowest value there
// - For case 1 and 2, set the new value of the node to 0
// - Case 1: the value is joining multiple CC's with seperate max heights...
//      - All the height values that are lower than the max height of the CC have their new value
// - Case 2: the value is joining one CC's with one height. Just merge the value to the connected component
// - Case 3: the value is a peak... do nothing
// The highest value can't be updated this way... but when two merge they can be updated

// We need values that aren't -1
// But also aren't the maximum peak
// Then we merge all the ones that aren't -1
// And we update all the peaks that are smaller than the biggest one
// If all neighbors are -1 then we can't set ans[i][j] to 0
//
// Store the coordinates of the highest values
// For all maximum heights in the CC, we have to store them in a place
// For all the leaders
//
// We need one array for the neighbors. If a neighbor is larger than the current node
// Then we set it to 0
