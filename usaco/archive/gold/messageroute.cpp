#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e5+5;
vector<int> adj_list[MX];

int N, M;
void bfs(int s) {
    queue<int> q;
    vector<bool> visited(N);
    vector<int> d(N, -1);
    vector<int> prev(N, -1);

    visited[s] = true;
    d[s] = 1;

    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto v: adj_list[x]) {
            if (!visited[v]) {
                visited[v] = true;
                d[v] = d[x] + 1;
                prev[v] = x;
                q.push(v);
            }
        }
    }
    vector<int> ans;
    int ptr = N-1;
    while (ptr != -1){
        ans.push_back(ptr + 1);
        ptr = prev[ptr];
    }
    reverse(ans.begin(), ans.end());

    int size = (int)ans.size();
    if (size == 1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << size << endl;
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}

void solve(){
    cin >> N >> M;

    for (int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        --a, --b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    bfs(0);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
