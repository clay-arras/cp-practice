#include <bits/stdc++.h>
using namespace std; 

const int MX = 1e5+5;
int n;
int visited[MX];
vector<int> adj_list[MX];

long long r=0, b=0;
void dfs(int s, int c){
    visited[s] = true;
    if (c == 0) r++;
    else if (c == 1) b++;

    for (int u : adj_list[s]){
        if (!visited[u]){
            dfs(u, (c+1)%2);
        }
    }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("io/input.txt", "r", stdin); */

    cin >> n;
    for (int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(0, 0);
    cout << r*b - 1LL*(n-1) << endl; 
}
