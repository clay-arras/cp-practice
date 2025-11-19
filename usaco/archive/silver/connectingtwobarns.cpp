#include <bits/stdc++.h>
using namespace std; 

const int MX = 5e5 + 2;
int N, M;

vector<int> adj_list[MX];
bool visited[MX];

vector<int> beg;
vector<int> ed;

void dfs(int s, int g){
    visited[s] = true;
    if (g == 1) beg.push_back(s);
    else if (g == 2) ed.push_back(s);

    for (int u : adj_list[s]){
        // if connected already change
        if (!visited[u]){
            dfs(u, g);
        }
    }
}

void solve(){
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(0, 1);
    dfs(N-1, 2);

    sort(beg.begin(), beg.end());
    sort(ed.begin(), ed.end());

    int i=0, j=0;
    int beg_len = (int)beg.size(), ed_len = (int)ed.size();

    int a=0, b=0;
    while (i < beg_len and j < ed_len){
        if (abs(beg[a]-ed[b]) > abs(beg[i]-ed[j])){
            a = i;
            b = j;
        }
       
        if (j == ed_len-1){
            i++;
            continue;
        }else if (i == beg_len-1){
            j++;
            continue;
        }
        if (beg[i] < ed[j]) i++;
        else if (beg[i] > ed[j]) j++;
    }
    
    a = beg[a];
    b = ed[b];
    if (abs(a - b) == 1) cout << 1 << "\n";
    else {
        int mid = (a+b)/2;
        cout << pow(abs(mid - a), 2) + pow(abs(mid - b), 2) << "\n";
    }

    beg.clear(); ed.clear();
    fill(visited, visited+N, false);
    for (int k=0; k<N; k++) adj_list[k].clear();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("../io/input.txt", "r", stdin); */
    
    int T; cin >> T; 
    while(T--){
        solve();
    }
}
// use dfs to label an array with ones and 2s and 0s
// then use two pointers to find a pair of 1s and 2s that are as close to each other as possible 
