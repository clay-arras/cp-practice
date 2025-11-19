#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

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

const int MX = 2e5+5;
vector<int> adj_list[MX];
vector<int> adj_listRev[MX];
vector<bool> visited;

void solve() {
    int N, M; cin >> N >> M;

    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj_list[a].push_back(b);
        adj_listRev[b].push_back(a);
    }

    int cc = N;
    DSU d; d.init(N);
    for (int i=0; i<N; i++) {
        for (int j=1; j<(int)adj_list[i].size(); j++) {
            int a = adj_list[i][j-1];
            int b = adj_list[i][j];
            cc -= d.unite(a, b);
        }
    }

    queue<int> q;

    cout << cc << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// Preliminary thoughts:
// If two cows are pointing at the same cow, then they are in that group
// All cows are connected components.
// We count the maximum amount of connected components
// We connect two cows if they admire the same thing
// Sort by cow A
// Keep track of the number of leaders: maintain int CC
//
// If two cows point at the same cow, then they have to share the same favorite color
// Use a map to convert the values to lexicographically minimum
// Start from the ones that are already connected
// Iterate through with an adjacency list
// Keep some sort of queue
//
// Keep a priority queue breath first search
// We keep a list of all the nodes that we are going to process
// When we join the values we check if this one has been set before
// We only set each value once
// Use a map to figure out which color points to which other color
//
// m[c1] = c2 where c1 admires to c2 color
// if (m[c1] != not set) maxColor++;
//
// Hint: when we merge one to another, we can append all the adjacency list to
// of the merged to the leader and run a search algorithm through it again
// How do we know which ones are going to be merged
// All the things pointing to one shit can be merged together
// We start with a bunch of colors and see which ones we can merge together
// We have to make sure that the arragement is possible
//
// Everything pointing to the thing needs to be visited. We start by merging all

