#include <bits/stdc++.h>
using namespace std; 

const int MX = 1e5+5;

int N, M;
int visited[MX];
vector<pair<int, char>> adj_list[MX];

bool bad = false;
void dfs(int s, int c){
    visited[s] = c;

    for (auto u : adj_list[s]){
        if (!visited[u.first]){
            if (u.second == 'S'){
                dfs(u.first, c);
            }else{
                dfs(u.first, (c+2)%2 + 1);
            }
        }
        if (u.second == 'S' and (visited[u.first] != visited[s])) bad = true;
        else if (u.second == 'D' and (visited[u.first] == visited[s])) bad = true;
    }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("io/input.txt", "r", stdin); */
   	freopen("revegetate.in", "r", stdin);
   	freopen("revegetate.out", "w", stdout);
    
    cin >> N >> M;
    for (int i=0; i<M; i++){
        char c; int u, v; cin >> c >> u >> v;
        --u, --v;
        adj_list[u].push_back({v, c});
        adj_list[v].push_back({u, c});

    }
    
    // impossible case cout << 0
    int ans=1;
    for (int i=0; i<N; i++){
        if (!visited[i]){
            dfs(i, 1);
            ans++;
        }
    }
    if (bad){
        cout << 0 << endl;
        return 0;
    }

    cout << 1;
    while(--ans) cout << 0;
    cout << endl;
}
