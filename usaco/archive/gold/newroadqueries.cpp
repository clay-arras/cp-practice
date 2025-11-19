#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// ans[a][b] is when a and b became part of the same component
// When we unite, we only unite the leaders.
// How do we keep track of the followers if we only unite the leaders
// Index each pair of cities
// Keep track of relevant cities. When two join and are the same index, we write the answer for that index
// Unordered set for each value

template <typename T>
std::set<T> getUnion(const std::set<T>& a, const std::set<T>& b) {
    std::set<T> result = a;
    result.insert(b.begin(), b.end());
    return result;
}

vector<int> ans;
struct DSU {
	vector<int> e;
    vector<set<int>> ls;

    void init(int N) {
        e = vector<int>(N,-1);
        ls = vector<set<int>> (N, set<int>());
    }
	int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }
	bool unite(int x, int y, int i) {
		x = get(x), y = get(y);
        if (x == y)
            return 0;

		if (e[x] > e[y])
            swap(x,y);

        /* vector<int> v; */
        /* auto it = set_union(ls[x].begin(), ls[x].end(), ls[y].begin(), ls[y].end(), v.begin()); */
        /* v.resize(it-v.begin()); */
        set<int>v = getUnion(ls[x], ls[y]);
        for (auto it=v.begin(); it!=v.end(); ++it)
            ans[*it] = i;

        merge(ls[x].begin(), ls[x].end(), ls[y].begin(), ls[y].end(), inserter(ls[x], ls[x].end()));
        ls[y].clear();

		e[x] += e[y];
        e[y] = x;

        return 1;
	}
};

void solve() {
    int N, M, Q; cin >> N >> M >> Q;

    vector<pair<int, int>> R;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        R.push_back({a, b});
    }

    DSU d; d.init(N);
    ans = vector<int>(Q, -1);
    for (int i=0; i<Q; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        d.ls[a].insert(i);
        d.ls[b].insert(i);
    }

    for (int i=0; i<N; i++) {
        d.unite(R[i].first, R[i].second, i+1);
        for (auto u : d.ls)
            cout << u << endl;;
        cout << endl << endl;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// Store the values. Make map that gives us a vector of all the values (like an adjacency list)
// Every time something is joined that has that value in it, we check all the values in the list
// We need some way to identify the value as a component
// When we merge, we have the two leaders merging
// With each leader we store the values of components that we need... When we merge we merge the two groups of values
// If any of them are found, then we eliminate them correspondingly
//
// Every time we merge, we update the components in Query
// O(M+Q)
// Go through algorithm again...
// It doesn't find it soon enough
