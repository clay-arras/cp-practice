#include <bits/stdc++.h>
using namespace std; 

const int MX = 20;
int N, K;
vector<int> adj_list[MX];
vector<int> q;
bool visited[MX];
set<int> ans;

void dfs(int s){
    visited[s] = true;
    q.push_back(s);

    for (int u : adj_list[s]){
        if (!visited[u]){
            dfs(u);
        }else if (auto j = find(q.begin(), q.end(), u) != q.end()){
            for (int i = j-1; i < (int)q.size(); i++){
                ans.insert(q[i]); 
            } 
        }
    }
    q.pop_back();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	freopen("../io/input.txt", "r", stdin);
    
    cin >> N >> K;
    for (int i=0; i<K; i++){
        int u, v, a, b; cin >> u >> v >> a >> b;
        --u, --v;
        if (a > b) adj_list[u].push_back(v);
        else if (a < b) adj_list[v].push_back(u);
    }

    for (int i=0; i<N; i++){
        if (!visited[i]){
            dfs(i);
        }
    }
    cout << (int)ans.size() << "\n";
}
