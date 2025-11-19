// I got the algorithm pretty easily but the implementation is hell. 

#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

int n; vector<vector<pair<int, int>>> l;
vector<bool> visited;
int ans[1000005];

void dfs(int v, int p){
	visited[v] = true;
	for (auto &[val, i]:l[v]){
		if (visited[val]) continue;
		ans[i] = p;
		dfs(val, 1^p);
	}
   
}

void solve(){
	cin >> n; l.resize(n); visited.resize(n);
	fill(visited.begin(), visited.end(), false);
	// fill(l.begin(), l.end(), {});
	vector<int> deg(n, 0);

	for (auto &t:l) t = {};
	for (int i=1; i<n; i++){
		int u, v; cin >> u >> v;
		--u, --v;
		l[u].push_back({v, i});
		l[v].push_back({u, i});
		deg[u]++;
		deg[v]++;
	}

	int v=0;
	for (int i=0; i<n; i++){
		if (deg[i] > 2){
			cout << "-1\n";
			return;
		}
		if (deg[i] == 1) v = i;
	}
	dfs(v, 2);

	for (int i=1; i<n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}

	return 0;
}
