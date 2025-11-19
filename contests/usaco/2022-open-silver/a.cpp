#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5+6;

long long N, ans;
int visited[MX];
vector<int> adj_list[MX];
vector<int> q;
int weights[MX];

void dfs(int s){
    visited[s] = 1;
    q.push_back(s);

    for (int u : adj_list[s]){
        if (visited[u] == 1){
            int m = 1e9+5;
            for (int i = (int)q.size()-1; i>=0; i--){
                m = min(m, weights[q[i]]);
                if (q[i] == u) break;
            }
            ans -= m;
        }
        if (!visited[u]) dfs(u);
    }
    q.pop_back();
    visited[s] = 2;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    cin >> N;
    for (int i=0; i<N; i++){
        long long a, w; cin >> a >> w;
        --a;
        adj_list[i].push_back(a);
        weights[i] = w;
        ans += w;
    }

    for (int i=0; i<N; i++){
        if (!visited[i]) dfs(i);
        q.clear();
    }
    cout << ans << endl;
}
