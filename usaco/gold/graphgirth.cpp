#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2500 + 5;
vector<int> adj_list[MX];

int N, M;
int BFS () {
    int ans = MX;
	vector<int> dist(N, INT_MAX);

	queue<int> q;
	dist[0] = 0; q.push(0);
	while (!q.empty()) {
		int x = q.front(); q.pop();

		for (int t: adj_list[x]) {
            if (dist[t] == INT_MAX) {
                dist[t] = dist[x]+1;
                q.push(t);
            }
        }
	}
    return ans;
}
void solve () {
    cin >> N >> M;

    while (M--) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    cout << BFS() << endl;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}
