#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
struct SegTree {
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; }

	vector<T> tree; int n;
	SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}

	void update(int pos, T val) {
		for (tree[pos += n] = val; pos /= 2;)
			tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, tree[b++]);
			if (e % 2) rb = f(tree[--e], rb);
		}
		return f(ra, rb);
	}
};

//   3   2    4   5   1   1   5   3
//   3   -1   2   1  -4   0   4   -2

//   0   1   2   3   4    5   6   7

//   3   4   6   7   3    1   5   3
//   3  -1   2   1  -4   -2   4  -2
//   t[a] + k
//   [b+1] - k

void solve(){
    int N, Q; cin >> N >> Q;

    vector<long long> A(N);
    for (auto &t : A)
        cin >> t;

    // Difference array:
    // A[0] is D[0]
    // Each next element is the difference from the first to the second
    vector<long long> D(N+1);
    D[0] = A[0], D[N] = 0;
    for (int i=1; i<N; i++)
        D[i] = A[i] - A[i-1];

    // Initialize SegTree
    SegTree t(N+1, 0LL);
    for (int i=0; i<=N; i++){
        t.update(i*1LL, D[i]);
    }

    // Update the difference array normally, find the points by getting the sum and adding D[0]
    while (Q--){
        int q; cin >> q;
        if (q == 1){
            int a, b, k; cin >> a >> b >> k;
            --a, --b;
            t.update(a, t.tree[a+N+1]+k);
            t.update(b+1, t.tree[b+2+N]-k);

        }else if (q == 2){
            int i; cin >> i;
            cout << t.query(0, i) << endl;
        }
    }
}

// We want to: update a range quickly, and find point values quickly
// Segment trees allows you to find a range quickly and update a point quickly
// Store a difference array in a segment tree

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
