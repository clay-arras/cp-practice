#include <bits/stdc++.h>
using namespace std; 

const int MX = 200;
int N; 
vector<pair<int, int>> coords;
vector<int> power;
vector<int> adj_list[MX];
bool visited[MX];

int can_reach=0;
void dfs(int s){
    visited[s] = true;
    can_reach++;

    for (int i=0; i<(int)adj_list[s].size(); i++){
        if (!visited[adj_list[s][i]]){
            dfs(adj_list[s][i]);
        }
    }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("../io/input.txt", "r", stdin); */
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    cin >> N;
    for (int i=0; i<N; i++){
        int x, y, p; cin >> x >> y >> p;
        coords.push_back({x, y});
        power.push_back(p);
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            int dist = pow(coords[i].first - coords[j].first, 2) + pow(coords[i].second - coords[j].second, 2);
            if (power[i]*power[i] >= dist){
                adj_list[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int i=0; i<N; i++){
        fill(visited, visited+N, false);
        can_reach=0;
        dfs(i);
        ans = max(can_reach, ans);
    }
    cout << ans << "\n";
}
