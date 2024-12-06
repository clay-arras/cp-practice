#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e5+4;
int N, M;
vector<int> ret;
vector<vector<int>> order;
bool visited[MX];

struct TopoSort {
	int N; vector<int> in, res;
	vector<vector<int>> adj;
	void init(int _N) {
        N = _N;
        in.resize(N);
        adj.resize(N);
    }
	void add_edge(int x, int y) {
        adj[x].push_back(y);
        in[y]++;
    }
	bool sort() {
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i=1; i<N; i++)
			if (!in[i]) q.push(i);
		while ((int)q.size()) {
			int x = q.top(); q.pop(); res.push_back(x);
			for (const int &i : adj[x])
				if (!(--in[i])) q.push(i);
		}
		return ((int)res.size() == N - 1);
	}
};

bool check(int X) {
	TopoSort T; T.init(N + 1);
	for (int i=0; i<X; i++) {
		for (int j=0; j<(int)(order[i].size()) - 1; j++) {
			T.add_edge(order[i][j], order[i][j + 1]);
		}
	}
	bool ans = T.sort();
	if (ans) ret = T.res;
	return ans;
}

void solve() {
    cin >> N >> M;
    order.resize(M);
    ret.resize(N);

    for (int i=0; i<M; i++) {
        int k; cin >> k;
		vector<int> v(k);
		for (int j=0; j<k; j++)
			cin >> v[j];
		order[i] = v;
    }

	int lo = 0, hi = M;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		check(mid) ? lo = mid : hi = mid - 1;
	}

    int cnt = -1;
    for (int i : ret) {
        cnt++;
        cout << i << (cnt == N-1 ? "" : " ");
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Binary search

*/
