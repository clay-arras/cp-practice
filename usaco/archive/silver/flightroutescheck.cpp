#include <bits/stdc++.h>
using namespace std; 

const int MX = 1e5+5;
int n, m;
bool visited[MX];
vector<pair<int, int>> adj_list[MX];

void dfs(int s, int dir){
    visited[s] = true;

    for (auto u : adj_list[s]){
        if (!visited[u.first] and u.second == dir){
            dfs(u.first, dir);
        }
    }
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("input.txt", "r", stdin); */

    cin >> n >> m;
    for (int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        --a, --b;
        adj_list[a].push_back({b, 1});
        adj_list[b].push_back({a, -1});
    }
    dfs(0, 1);
    for (int i=0; i<n; i++){
        if (!visited[i]){
            cout << "NO\n";
            cout << 1 << " " << i+1 << endl;
            return 0;
        }
    }
    fill(visited, visited+n, false);
    dfs(0, -1);
    for (int i=0; i<n; i++){
        if (!visited[i]){
            cout << "NO\n";
            cout << i+1 << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES\n";
}
