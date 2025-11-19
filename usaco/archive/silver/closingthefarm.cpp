#include <bits/stdc++.h>
using namespace std; 

const int MX = 3000;
int N, M; 
int closed[MX];
int visited[MX];
vector<int> adj_list[MX];
int cnt=0;

void dfs(int s){
    visited[s] = true;
    cnt++;

    for (int i=0; i<(int)adj_list[s].size(); i++){
        if (!visited[adj_list[s][i]] and !closed[adj_list[s][i]]){
            dfs(adj_list[s][i]);
        }
    }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("../io/input.txt", "r", stdin); */
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> N >> M;
    for (int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i=0; i<N; i++){
        int p; cin >> p; 
        --p;
        fill(visited, visited+N, false); cnt=0;

        dfs(p);
        cout << (cnt == N-i ? "YES" : "NO") << "\n";
        closed[p] = true;
    }
}
