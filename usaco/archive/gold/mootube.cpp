#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// Edge list
// Get rid of path and height compression optimizations
// Set the leader to which one comes first
// For each edge, set some sort of seperate array that measures the relevance
// Merge takes (u, v, e)
// When you search, find the values of u and v and add them together
// Time complexity should be O(N^2)
//
//
// Use DSU to make some sort of data structure
// Use the DSU, set the relevance as the leader term
// Merge opposing stuff, use the leader which is the lowest relevance.
// That way, you can find the relevance of
//
// We want to relevance of two seperate subjects
// How do I find the relevance of any two subjects that aren't listed
//
// Hint 1: Consider the queries offline in an easier order
//
// Algo:
// Sort the edges in decreasing order
// For each query, sort the queries in decreasing order as well
// The queries

struct Edge{ int u, v, w; };
bool operator<(const Edge& x, const Edge& y) { return x.w < y.w; }
struct Query{ int v, k, i; };
bool operator<(const Query& x, const Query& y) { return x.k < y.k; }


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

	bool unite(int x, int y) { // union by size
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

void solve(){
    int N, Q; cin >> N >> Q;

    vector<Edge> e;
    for (int i=0; i<N-1; i++){
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        e.push_back({u, v, w});
    }

    vector<Query> q;
    for (int i=0; i<Q; i++){
        int k, v; cin >> k >> v;
        --v;
        q.push_back({v, k, i});
    }

    sort(q.rbegin(), q.rend());
    sort(e.rbegin(), e.rend());

    DSU d;
    d.init(N);
    int j=0;

    vector<int> ans(Q);
    for (int i=0; i<Q; i++){
        int v = q[i].v;
        int k = q[i].k;

        for (; j<N-1; j++){
            if (e[j].w < k)
                break;
            d.unite(e[j].u, e[j].v);
        }
        ans[q[i].i] = d.size(v)-1;
    }
    for (int i : ans)
        cout << i << endl;

    // Keep track of how many connected components
    // At first, it should equal to the number of vertices N
    // If a merge is successful, then reduce the number of connected components
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
