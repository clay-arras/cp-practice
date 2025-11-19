#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

const int MX = 3e5 + 5;
vector<int> adj_list[MX];

bool visited[MX];
bool visited2[MX];
int n;
int count1 = 0;
int count2 = 0;

void dfs(int s){
    visited[s] = true;
    count1++;

    for (int u : adj_list[s]){
        if (!visited[u] and !visited2[u])
            dfs(u);
    }
}

int dfs2(int s){
    visited2[s] = true;

    int check = 0;
    pair<int, int> next = make_pair(-1, -1);
    for (int u : adj_list[s]){
        if (!visited2[u]){
            fill(visited, visited+n, 0);
            count1 = 0;
            dfs(u);
            if (count1 > next.first){
                next.first = count1;
                next.second = u;
            }else if (count1 == next.first){
                int res1 = dfs2(u);
                int res2 = dfs2(next.second);
                return 1 + max(res1, res2);
            }
            check++;
        }
    }
    if (check)
        return 1 + dfs2(next.second);
    /* return 1; */
    return 1;
}

void solve(){
    cin >> n;
    for (int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int val = dfs2(0);
    cout << val << endl;
    /* cout << n << endl; */
    /* cout << n - val - 1 << endl; */
    /* cout << endl; */
    /* cout << count2 << endl; */

    count1 = 0, count2 = 0;
    fill(visited2, visited2+n, 0);
    fill(adj_list, adj_list+n, vector<int>());
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
