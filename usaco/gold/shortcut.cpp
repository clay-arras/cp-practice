#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long mxV = 1e18;
const int MX = 1e5+5;
vector<pair<int, int>> adj_list[MX];

void solve(){
    int N, M, T; cin >> N >> M >> T;

    vector<int> c(N);
    for (int &t : c)
        cin >> t;

    for (int i=0; i<M; i++){
        int a, b, t; cin >> a >> b >> t;
        --a, --b;
        adj_list[a].push_back({b, t});
        adj_list[b].push_back({a, t});
    }

    vector<long long> d(N, mxV);
    vector<bool> visited(N, 0);
    priority_queue<pair<long long, int>> q;

    vector<int> prev(N, -1);

    d[0] = 0;
    q.push({0, 0});

    while (!q.empty()){
        int curr = q.top().second;

        q.pop();
        if (visited[curr]) continue;
        visited[curr] = true;

        for (auto u : adj_list[curr]){
            int w = u.second, v = u.first;

            if (d[v] > d[curr] + w){
                d[v] = d[curr] + w;
                prev[v] = curr;
                q.push({-d[v], v});
            }else if (w + d[curr] == d[v]
                    and curr < prev[v]){
                prev[v] = curr;
                q.push({-d[v], v});
            }
        }
    }
    vector<long long> cowTraffic(N, 0);
    for (int i=0; i<N; i++){
        int ptr = i;
        while (ptr != -1){
            cowTraffic[ptr] += c[i];
            ptr = prev[ptr];
        }
    }

    long long ans = 0;
    for (int i=0; i<N; i++)
        ans = max(ans, cowTraffic[i]*1LL*(d[i] - T));

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}

// Sort the output paths by the greatest one that the cows will exit from
// That is, for every edge that is used, we look at the once that most cows have to get through to get to their destination, and reduce that to time T

/* #include <bits/stdc++.h> */
/* using namespace std; */

/* #ifdef LOCAL */
/* #include "algo/debug.h" */
/* #define open(x) freopen(x, "r", stdin); */
/* #else */
/* #define open(x) */
/* #endif */

/* // Algorithm: Run Dijkstras on the graph once to figure out the starting travel time for the cows */
/* // Use a tuple or another data structure, make the tuple (-d, v_from, v) -- also store the number of cows (once we get to a node and it hasn't been visited, add the number of cows to that node) */
/* // At the end we will find the node with the greatest amount of cows that go through it and decrease the existing time by that amount */
/* // */
/* // Keep an array called cows_that_visited[i] is the cows that visited that node */
/* // Get the node that most cows will have visited (aka the node that is present in most paths) -- if we are visiting this node for the first time, add to the cows in that node */

/* const int MX = 1e5+5; */
/* const long long mxV = LLONG_MAX - 9e2; */

/* vector<pair<int, int>> adj_list[MX]; */

/* int N, M, T; */
/* vector<int> c; */
/* vector<long long> cowTraffic; */
/* pair<long long, long long> maxTraffic = {-1, -1}; */

/* long Dijkstras(){ */
/*     vector<long long> d(N, mxV); */
/*     vector<bool> visited(N, 0); */
/*     priority_queue<pair<long long, pair<int, int>>> q; */
/*     // First is the distance, second is the edge */

/*     d[0] = 0; */
/*     q.push({0, {0, 0}}); */

/*     while (!q.empty()){ */
/*         int curr = q.top().second.second; */
/*         /1* int prev = q.top().second.second; *1/ */

/*         q.pop(); */
/*         if (visited[curr]) continue; */
/*         visited[curr] = true; */

/*         for (auto u : adj_list[curr]){ */
/*             int w = u.second, v = u.first; */

/*             if (d[v] > d[curr] + w){ */
/*                 // We're making the connection -- update cowTraffic */

/*                 d[v] = d[curr] + w; */
/*                 cowTraffic[curr] += cowTraffic[v]; */
/*                 maxTraffic = max(maxTraffic, {cowTraffic[v], v}); */
/*                 q.push({-d[v], {-curr, v}}); */
/*             } */
/*         } */
/*     } */
/*     long long sum = 0; */
/*     for (int i=0; i<N; i++){ */
/*         sum += c[i]*d[i]; */
/*     } */

/*     return sum; */
/* } */

/* void solve(){ */
/*     cin >> N >> M >> T; */

/*     c = vector<int> (N); */
/*     for (int &t : c) */
/*         cin >> t; */

/*     for (int i=0; i<M; i++){ */
/*         int a, b, t; cin >> a >> b >> t; */
/*         --a, --b; */
/*         adj_list[a].push_back({b, t}); */
/*         adj_list[b].push_back({a, t}); */
/*     } */
/*     cowTraffic = vector<long long> (N); */
/*     for (int i=0; i<N; i++) */
/*         cowTraffic[i] = c[i]; */

/*     int init = Dijkstras(); */

/*     cout << cowTraffic << endl; */
/*     adj_list[0].push_back({maxTraffic.second, T}); */
/*     adj_list[maxTraffic.second].push_back({0, T}); */

/*     // Add the edge then run Dijkstras again lmao */
/*     int post = Dijkstras(); */
/*     cout << init - post << endl; */
/*     cout << post << endl; */
/* } */

/* int main() { */
/*     ios::sync_with_stdio(0); cin.tie(0); */
/*     open("input.txt"); */

/*     int t=1; */
/*     while(t--){ */
/*         solve(); */
/*     } */
/* } */

/* // Sort the output paths by the greatest one that the cows will exit from */
/* // That is, for every edge that is used, we look at the once that most cows have to get through to get to their destination, and reduce that to time T */
