#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// Make a graph where every point on the graph seperated by 3 is an edge

const int MX = 1e2 + 3;
const long long mxV = 1e18;
/* struct Point { long long x, y; }; */
/* #define Point pair<long, long> */

vector<pair<long long,
    pair<long long, long long>>> adj_list[MX][MX];

int N, T;
long long Dijkstras(){
    vector<vector<long long>> d
        (N, vector<long long> (N, mxV));
    vector<vector<bool>> visited
        (N, vector<bool> (N, 0));

    priority_queue<pair<long long,
        pair<long long, long long>>> q;

    d[0][0] = 0;
    q.push({0, {0, 0}});
    while (!q.empty()){
        long long x = q.top().second.first;
        long long y = q.top().second.second;
        q.pop();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        for (auto u : adj_list[x][y]){
            long long w = u.first,
                 vx = u.second.first, vy = u.second.second;

            if (d[vx][vy] > d[x][y] + w){
                d[vx][vy] = d[x][y] + w;
                q.push({-d[vx][vy], {vx, vy}});
            }
        }

        for (int it=-2; it<=0; it++){
            for (int jt=-2; jt<=0; jt++){
                int x = N-1 + it, y = N-1 + jt;
                int dist = abs(it) + abs(jt);

                if (dist > 2)
                    continue;
                if (x < 0 or x >= N or y < 0 or y >= N)
                    continue;

                d[N-1][N-1] = min(d[N-1][N-1], d[x][y] + T*dist);
            }
        }
    }
    return d[N-1][N-1];
}

int dx[] = {1, 0, -1, 0, 3, 0, -3, 0, 2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {0, 1, 0, -1, 0, 3, 0, -3, 1, -1, 2, -2, 2, -2, 1, -1};

void solve(){
    cin >> N >> T;

    int arr[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            cin >> arr[i][j];
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            /* for (int it : dx) for (int jt : dy){ */
            for (int itt=0; itt<16; itt++){
                int it = dx[itt], jt = dy[itt];
                int x = i + it, y = j + jt;
                if (x < 0 or x >= N or y < 0 or y >= N)
                    continue;

                adj_list[i][j].push_back({arr[x][y]+3*T, {x, y}});
            }

        }
    }
    long long ans = Dijkstras();
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}

/* #include <bits/stdc++.h> */
/* using namespace std; */

/* #ifdef LOCAL */
/* #include "algo/debug.h" */
/* #define open(x) freopen(x, "r", stdin); */
/* #else */
/* #define open(x) */
/* #endif */

/* // Make a graph where every point on the graph seperated by 3 is an edge */

/* const int MX = 1e2 + 3; */
/* const long long mxV = 1e18; */
/* /1* struct Point { long long x, y; }; *1/ */
/* #define Point pair<long, long> */
/* #define x first */
/* #define y second */

/* vector<pair<long long, Point>> adj_list[MX][MX]; */

/* int N, T; */
/* long long Dijkstras(){ */
/*     vector<vector<long long>> d */
/*         (N, vector<long long> (N, mxV)); */
/*     vector<vector<bool>> visited */
/*         (N, vector<bool> (N, 0)); */

/*     priority_queue<pair<long long, Point>> q; */

/*     d[0][0] = 0; */
/*     q.push({0, {0, 0}}); */
/*     while (!q.empty()){ */
/*         long long x = q.top().second.x; */
/*         long long y = q.top().second.y; */

/*         q.pop(); */
/*         if (visited[x][y]) continue; */
/*         visited[x][y] = true; */

/*         for (auto u : adj_list[x][y]){ */
/*             long long w = u.first, */
/*                  vx = u.second.x, vy = u.second.y; */

/*             if (d[vx][vy] > d[x][y] + w){ */
/*                 d[vx][vy] = d[x][y] + w; */
/*                 q.push({-d[vx][vy], {vx, vy}}); */
/*             } */
/*         } */
/*     } */

/*     long long mnV = mxV; */
/*     for (int it=-2; it<=0; it++){ */
/*         for (int jt=-2; jt<=0; jt++){ */
/*             int x = N-1 + it, y = N-1 + jt; */
/*             if (abs(it) + abs(jt) > 2) */
/*                 continue; */
/*             if (x < 0 or x >= N or y < 0 or y >= N) */
/*                 continue; */

/*             mnV = min(mnV, d[x][y] + T*(abs(jt) + abs(it))); */
/*         } */
/*     } */
/*     return mnV; */
/* } */

/* void solve(){ */
/*     cin >> N >> T; */

/*     int arr[N][N]; */
/*     for (int i=0; i<N; i++){ */
/*         for (int j=0; j<N; j++) */
/*             cin >> arr[i][j]; */
/*     } */

/*     for (int i=0; i<N; i++){ */
/*         for (int j=0; j<N; j++){ */

/*             for (int it=-3; it<=3; it++){ */
/*                 for (int jt=-3; jt<=3; jt++){ */
/*                     int x = i + it, y = j + jt; */
/*                     if (abs(jt) + abs(it) != 3) */
/*                         continue; */
/*                     if (x < 0 or x >= N or y < 0 or y >= N) */
/*                         continue; */

/*                     adj_list[i][j].push_back({arr[x][y]+3*T, {x, y}}); */
/*                 } */
/*             } */

/*         } */
/*     } */
/*     long long ans = Dijkstras(); */
/*     cout << ans << endl; */
/* } */

/* int main() { */
/*     ios::sync_with_stdio(0); cin.tie(0); */
/*     open("input.txt"); */

/*     /1* freopen("visitfj.in", "r", stdin); *1/ */
/*     /1* freopen("visitfj.out", "w", stdout); *1/ */

/*     int t=1; */
/*     while(t--){ */
/*         solve(); */
/*     } */
/* } */
