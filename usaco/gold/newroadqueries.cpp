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

void solve(){
    int n, m, q; cin >> n >> m >> q;

    for (int i=0; i<m; i++){

    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
