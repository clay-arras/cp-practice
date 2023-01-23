#include <bits/stdc++.h>
using namespace std; 

const int MX = 2e5+5;
int n, m; 
int visited[MX];
vector<int> adj_list[MX];
set<int> ans;

void dfs(int s, int dist=0){
    visited[s] = dist + 1;
    if (dist == 0) {
        ans.insert(s);
    }

    for (int u : adj_list[s]){
        if(!visited[u]){
            dfs(u, !dist);
        } 
    }
}

void solve(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(0);

    int sz = (int)ans.size();
    if (sz > n/2){
        cout << n - sz << endl;
        for (int i=0; i<n; i++){
            if(!ans.count(i)) cout << i+1 << " ";
        }
    }else{
        cout << sz << endl;
        for (int i:ans) cout << i+1 << " ";
    }

    cout << endl;
    for (int i=0; i<n; i++) adj_list[i].clear();
    fill(visited, visited+n, false);
    ans.clear();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("io/input.txt", "r", stdin); */
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}
