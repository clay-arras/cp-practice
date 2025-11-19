#include <bits/stdc++.h>
using namespace std; 

const int MX = 1e5 + 5;
int n, m;

vector<int> adj_list[MX];
bool visited[MX];

void dfs(int s){
    visited[s] = true;
    for (int i=0; i<(int)adj_list[s].size(); i++){
        if (!visited[adj_list[s][i]]){
            dfs(adj_list[s][i]);
        }
    }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("../io/input.txt", "r", stdin); */
   	
   	cin >> n >> m;
    for (int i=0; i<m; i++){
        int u, v; cin >> u >> v; 
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> roots;
    for (int i=0; i<n; i++){
        if (!visited[i]){
            dfs(i);
            roots.push_back(i+1);
        }
    }

    int len = (int)roots.size();
    cout << len-1 << "\n";
    for (int i=0; i<len-1; i++){
        cout << roots[i] << " " << roots[i+1] << "\n";
    }
}

 
