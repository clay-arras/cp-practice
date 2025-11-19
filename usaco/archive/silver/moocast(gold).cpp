#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
int N;

vector<int> adj_list[MX];
int dist[MX][MX];
bool visited[MX];
int x[MX], y[MX];
int cnt=0;

void dfs(int s){
	visited[s] = true;
	cnt++;
	for (int u : adj_list[s]){
		if (!visited[u]) dfs(u);
	}
}

bool check(int dis){
	fill(visited, visited+N, 0); cnt=0;
	for (int i=0; i<N; i++) adj_list[i].clear();

	for (int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if (dis >= dist[i][j]){
				adj_list[i].push_back(j);
				adj_list[j].push_back(i);
			}
		}
	}

	dfs(0);
	return cnt == N;
}
int bs(int lo, int hi, function<bool(int)> f) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	cin >> N;
	for(int i=0; i<N; i++) cin >> x[i] >> y[i];
	int max_dist=0;
	for (int i=0; i<N; i++){
		for (int j=i+1; j<N; j++){
			dist[i][j] = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
			max_dist = max(max_dist, dist[i][j]);
		}
	}
	cout << bs(1, max_dist, check) << endl;
}
