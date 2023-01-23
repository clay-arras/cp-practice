// bug: forgot to erase after each test
#include <bits/stdc++.h>
using namespace std; 

const int MX = 105;
int c=-1, p=-1, k;
vector<int> adj_list[MX];
vector<pair<int, int>> edges;
bool visited[MX];
int cnt=0;

void dfs(int s){
    visited[s] = true;
    cnt++;

    int m = edges[k].first;
    int n = edges[k].second;
    for (int u : adj_list[s]){
        if ((u == m and s == n) or (s == m and u == n)) continue;
        if (!visited[u]){
           dfs(u); 
        }
    }
}

int solve(){
    cin >> p >> c;
    if (c==0 and p==0){
        return 0;
    }
    
    for (int i=0; i<c; i++){
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        edges.push_back({a, b});
    }

    int ans=true;
    for (k=0; k<c; k++){
        dfs(0);
        if (cnt < p) ans=false;
        fill(visited, visited+p, false); cnt=0;
    }
    for (int i=0; i<p; i++) adj_list[i].clear(); 
    fill(visited, visited+p, false); cnt=0;
    edges.clear();

    cout << (ans ? "No" : "Yes") << endl;
    return 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("io/input.txt", "r", stdin); */
   
    while(solve());
}
