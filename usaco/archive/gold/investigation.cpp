#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long MOD = 1e9+7;
const long MX = 1e5+5;
const long long mxV = 1e18;

vector<pair<int, int>> adj_list[MX];
vector<long long> num_paths, min_paths, max_paths;
int N, M;

long long Dijkstras(int s){
    vector<long long> d(N, mxV);
    vector<bool> visited(N, 0);
    priority_queue<pair<long long, long long>> q;

    d[s] = 0, num_paths[s] = 1;
    q.push({0, s});
    while (!q.empty()){
        int x = q.top().second; q.pop();
        if (visited[x]) continue;
        visited[x] = true;

        for (auto u : adj_list[x]){
            long long w = u.first, v = u.second;
            long long alt = d[x] + w;

            if (d[v] == alt){
                num_paths[v] += num_paths[x];
                num_paths[v] %= MOD;

                min_paths[v] = min(min_paths[v], min_paths[x]+1);
                max_paths[v] = max(max_paths[v], max_paths[x]+1);
            }else if (d[v] > alt){
                d[v] = alt;
                min_paths[v] = min_paths[x] + 1;
                max_paths[v] = max_paths[x] + 1;
                num_paths[v] = num_paths[x];
                q.push({-d[v], v});

            }
        }
    }
    return d[N-1];
}

void solve(){
    cin >> N >> M;

    for (int i=0; i<M; i++){
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        adj_list[a].push_back({c, b});
    }

    num_paths = vector<long long> (N, 0LL);
    min_paths = vector<long long> (N, 0LL);
    max_paths = vector<long long> (N, 0LL);

    long long min_path = Dijkstras(0);
    cout << min_path << " " << num_paths[N-1] << " "
        << min_paths[N-1] << " " << max_paths[N-1] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}

/* // Keep a num_paths array. Every time two path values are equal, we can increment the num_paths[i] at node i. */
/* // Every time we add a node to the priority queue, we also set the num_paths to the previous num_paths */
/* // Every time we add a node we can also take the maxmimum between the two, vice versa for the minimum */
/* // - Otherwise if it's the most optimal path we can just increment the values */
