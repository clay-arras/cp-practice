#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct Node { int x, y, w; };
bool operator<(const Node& a, const Node& b) { return a.w < b.w; }

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int N, M;

vector<int> g;
vector<int> ans;

struct DSU {
	vector<int> e;
    vector<vector<Node>> h;
    void init(int V) {
        e = vector<int>(V,-1);
        h = vector<vector<Node>>(V, vector<Node>(0));
    }

	int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }

	int size(int x) {
        return -e[get(x)];
    }

	bool unite(int x, int y, int currH) {
		x = get(x), y = get(y);
        if (x == y)
            return 0;

        if (h[x][0].w == h[y][0].w) {
            h[x].insert(h[x].end(), h[y].begin(), h[y].end());

        } else {
            if (h[x][0].w < h[y][0].w)
                swap(x, y);

            for (auto n : h[y]) {
                if (n.w == -1)
                    continue;
                ans[n.x*M + n.y] = max(0, abs(n.w - currH));
            }
        }
        h[y] = vector<Node>(1, {-1, -1, -1});

		e[x] += e[y];
        e[y] = x;

        return 1;
	}
};

vector<Node> countSort(vector<Node> in, int m) {
	int len = (int)in.size();
	vector<int> count(m+1);
	vector<Node> out(len);

	for (Node c : in) {
		int i = c.w;
		count[m-i]++;
	}

	for (int i=1; i<=m; i++)
        count[i] += count[i-1];

	for (int i = len-1; i >= 0; i--) {
		count[m-in[i].w]--;
		out[count[m-in[i].w]] = in[i];
	}

	return out;
}

void solve(){
    cin >> N >> M;;

    g = vector<int>(N*M, -1);
    ans = vector<int>(N*M, -1);

    vector<Node> e;
    DSU d; d.init(N*M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int t; cin >> t;
            int pos = i*M + j;

            ans[pos] = t, g[pos] = t;
            e.push_back({i, j, t});
            d.h[pos].push_back({i, j, t});
        }
    }
    e = countSort(e, N*M);

    for (int it=0; it<(int)e.size(); it++) {
        int i = e[it].x;
        int j = e[it].y;

        for (int k=0; k<4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            int thisV = i*M + j;
            int nextV = x*M + y;
            int currH = g[thisV];

            if (x>=0 and x<N and y>=0 and y<M) {
                if (g[thisV] <= g[nextV]) {
                    d.unite(thisV, nextV, currH);

                    if (g[thisV] != g[nextV]) {
                        ans[thisV] = 0;
                    }
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cout << ans[i*M+j] << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// RIGHT ALGO WRONG IMPLEMENTATION

// Go from the lowest peak
// We connect it to all the neighbors that are higher than it (all the lower nodes should have already connected)
// For each CC, we keep track of the highest value
//
// Go from the highest peak
// We connect the high peak to all the neighbors that are higher than it
// For each CC we keep track of the highest value
// Every time we join a new value to the component, then it's impossible for it to be lower...
// That means that any peak that is joined has to be the lowest value there
// - For case 1 and 2, set the new value of the node to 0
// - Case 1: the value is joining multiple CC's with seperate max heights...
//      - All the height values that are lower than the max height of the CC have their new value
// - Case 2: the value is joining one CC's with one height. Just merge the value to the connected component
// - Case 3: the value is a peak... do nothing
// The highest value can't be updated this way... but when two merge they can be updated

// We need values that aren't -1
// But also aren't the maximum peak
// Then we merge all the ones that aren't -1
// And we update all the peaks that are smaller than the biggest one
// If all neighbors are -1 then we can't set ans[i][j] to 0
//
// Store the coordinates of the highest values
// For all maximum heights in the CC, we have to store them in a place
// For all the leaders
//
// We need one array for the neighbors. If a neighbor is larger than the current node
// Then we set it to 0

