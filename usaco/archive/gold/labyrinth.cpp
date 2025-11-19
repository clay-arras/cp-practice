#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void BFS (int N, int A, int B, vector<vector<int>> adj_list) {
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
}

int N, M;
int conv (int A, int B) {
    return A*M + B;
}

void solve() {
    cin >> N >> M;

    int A=-1, B=-1;
    vector<int> grid(N*M, 0);
    for (int i=0; i<N; i++) {
        string s; cin >> s;

        for (int j=0; j<M; j++) {
            if (s[j] == 'A')
                A = conv(i, j);
            if (s[j] == 'B')
                B = conv(i, j);
            if (s[j] == '#')
                grid[conv(i, j)] = 1;
        }
    }

    vector<vector<pair<int, char>>> adj_list
        (N*M, vector<pair<int, char>>());
    for (int i=0; i<N*M; i++) {
        if (i % M != 0) {
            adj_list[i].push_back({i-1, "R"});
            adj_list[i-1].push_back({i, "L"});
        }
        if (i >= M) {
            /* adj_list[i].push_back(i-M); */
            /* adj_list[i-M].push_back(i); */
        }
    }

    BFS(N*M, A, B, adj_list);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}
