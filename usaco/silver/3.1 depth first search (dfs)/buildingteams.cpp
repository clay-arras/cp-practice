#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

const int MX = 2e5+10;
int M, N;
bool bad;
vector<int> adj_list[MX];
vector<bool> group(MX);
vector<bool> visited(MX);

void dfs(int s=0, bool g=0){
	visited[s] = true;
	group[s] = g;
	for (int i:adj_list[s]){
		if (visited[i]){
			if (group[i] == g) bad = true;
		}else{
			dfs(i, !g);
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	cin >> N >> M;
   	for (int i=0, u, v; i<M; i++){
   		cin >> u >> v;
   		--u, --v;
   		adj_list[u].pb(v);
   		adj_list[v].pb(u);
   	}

   	for (int i=0; i<N and !bad; i++){
   		if (!visited[i]) dfs(i);
   	}

   	if (bad) cout << "IMPOSSIBLE\n";
   	else{
   		for (int i=0; i<N; i++){
   			cout << group[i] + 1 << " ";
   		}
   		cout << "\n";
   	}
}
