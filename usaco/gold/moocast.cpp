#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// We're looking for the smallest set of distances (with the minimum maximum) such that the edges form a tree. A tree is when the DSU has only one connected component
// We will merge two values if it reduces the connected component, then we will calculate the minimum between those distances
//
// How do we reduce the size of X
// Edge list, only add the edge if it is small

struct Edge{ int u, v; long long w; };
bool operator<(const Edge& x, const Edge& y) { return x.w < y.w; }

struct DSU {
    vector<int> e;
    void init(int N) {
        e = vector<int>(N,-1);
    }

    int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }

    int size(int x) {
        return -e[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;

        if (e[x] > e[y])
            swap(x,y);
        e[x] += e[y];
        e[y] = x;

        return 1;
    }
};

const int MX = 1e3+3;
vector<int> x(MX), y(MX);

long long xSquared(int i, int j){
    return pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2);
}

void solve(){
    int N; cin >> N;

    for (int i=0; i<N; i++)
        cin >> x[i] >> y[i];

    vector<Edge> e;
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            int xS = xSquared(i, j);
            e.push_back({i, j, xS});
        }
    }
    sort(e.begin(), e.end());

    DSU d;
    d.init(N);

    long long maxEdge = 0;
    int cc = N;

    for (int i=0; i<(int)e.size(); i++){
        if (d.unite(e[i].u, e[i].v)){
            maxEdge = max(maxEdge, e[i].w);
            cc--;
        }
    }
    cout << maxEdge << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
