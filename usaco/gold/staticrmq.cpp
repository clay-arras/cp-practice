#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template <class T>
struct RMQ {
	vector<T> v; vector<vector<int>> jmp;
    int level(int x) {
        return 31-__builtin_clz(x);
    }
	int cmb(int a, int b) {
        if (v[a] == v[b])
            return min(a, b);
		return (v[a] < v[b] ? a : b);
    }
	void init(const vector<T>& initV) {
		v = initV;
        int sz = (int)v.size();
        jmp = { vector<int>(sz) };
		iota(jmp[0].begin(), jmp[0].end(), 0);
		for (int j=1; (1<<j)<=sz; ++j) {
			jmp.push_back(vector<int>(sz-(1<<j)+1));
            for (int i=0; i<(int)jmp[j].size(); i++)
                jmp[j][i] = cmb(jmp[j-1][i], jmp[j-1][i+(1<<(j-1))]);
		}
	}
	int index(int l, int r) {
		assert(l <= r);
        int dist = level(r-l+1);
		return cmb(jmp[dist][l], jmp[dist][r-(1<<dist)+1]);
    }
	T query(int l, int r) {
        return v[index(l,r)];
    }
};

void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> v(N);
    for (int &t : v)
        cin >> t;

    RMQ<int> R;
    R.init(v);
    while (Q--) {
        int l, r; cin >> l >> r;
        cout << R.query(l, r-1) << endl;
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

