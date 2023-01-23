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

void solve(){
    int N; cin >> N;

    vector<int> h(N);
    for (int &t : h)
        cin >> t;

    SegTree <long long> T(N, 0LL);
    for (int i=0; i<N; i++){
        pair<int, int> slope = {h[i+1]-h[i], 1};

        for (int j=i+1; j<N; j++){
            if ((h[j]-h[i])*1.0/(j-i) >= slope.first*1.0/slope.second){
                slope = {h[j]-h[i], j-i};
                T.update(j, T.tree[N+j] + 1);
            }
        }
    }

    int Q; cin >> Q;
    while (Q--){
        int pos, inc; cin >> pos >> inc;
        --pos;

        int old = T.query(0, N);
        // Update the segment tree
        // Calculate the new segment tree and then update the values
        // If we use the old slope calculation, then we don't have the before and after
        // Just do it
    }
    // For all existing lines we have a height, and if you go past that height we can't sum it
}

/* There are N (1≤N≤2000) evenly spaced mountains in a row. These can be expressed as an array of heights h1,h2,…,hN. For a mountain i, you can see another mountain j if there are no mountains strictly higher than the line of sight connecting the tops of mountain j and i. Formally, for two mountains i<j, they can see each other if there is no k such that i<k<j and (k,hk) is above the line segment connecting (i,hi) and (j,hj). There are Q (1≤Q≤2000) updates where the height of one mountain increases. Find the total number of unordered pairs of mountains that see each other after each update. */

// Definitely a segment tree or point range update sum problem
//
// If we lock on one mountain, we are keeping track of the maximum peak. If we update that maximum peak
// Then we can count one. Otherwise we ignore it because it is smaller than the previous maximum peak and we can't see it.
// We also know that if the maximum peak is greater than the current peak, then we end
//
// We take N time to iterate through the array, We take logN time to update the range sum.. We have Q queries.
// We can keep track of all mountains who can see this particular mountain
//
// Have the number of subsequences that end at that number instead... Take minimum instead of maximum
// When we iterate backwards to 0, we update the one we are on. When we iterate forward we update the one that it ends on
// Algorithm is QNlogN. We need to iterate over the array (keep an array just in case) and see which ones need updating
// We can iterate over it and calculate which ones this specific i can see, and then if it can't see it anymore we decrement it
// What about the ones that end at that value...

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
