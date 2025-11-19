// Check bounds of problems
#include <bits/stdc++.h>
using namespace std; 

const int MX = 1e5 + 5;
int N, M; 
int max_x, max_y, min_x, min_y;
vector<pair<int, int>> coords;
vector<int> adj_list[MX];
bool visited[MX];

void dfs(int s){
    visited[s] = true;

    int x = coords[s].first, y = coords[s].second;
    max_x = max(max_x, x);
    min_x = min(min_x, x);
    max_y = max(max_y, y);
    min_y = min(min_y, y);

    for (int i=0; i<(int)adj_list[s].size(); i++){
        if (!visited[adj_list[s][i]]){
            dfs(adj_list[s][i]);
        }                                                     
    }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("../io/input.txt", "r", stdin); */
   
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    cin >> N >> M;
    for (int i=0; i<N; i++){
        int x, y; cin >> x >> y;
        coords.push_back({x, y});
    }

    for (int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    long long min_per = 2e9+5;
    for (int i=0; i<N; i++){
        min_x = min_y = 2e9+5;
        max_x = max_y = 0; 
        if (!visited[i]){
            dfs(i);
            long long per = 2*((max_x - min_x)+(max_y - min_y));
            min_per = min(min_per, per); 
        }
    }
    cout << min_per << "\n";
}
