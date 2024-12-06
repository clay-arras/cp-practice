#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template <int... ArgsT>
struct BIT {
    int val = 0;
    void update(int val) {
        this->val += val;
    }
    int query() {
        return val;
    }
};

template <int N, int... Ns>
struct BIT<N, Ns...> {
    BIT<Ns...> bit[N + 1];
    template<typename... Args>
    void update(int pos, Args... args) {
        for (; pos <= N; bit[pos].update(args...), pos += lastbit(pos));
    }

    template<typename... Args>
    int query(int l, int r, Args... args) {
        int ans = 0;
        for (; r >= 1; ans += bit[r].query(args...), r -= lastbit(r));
        for (--l; l >= 1; ans -= bit[l].query(args...), l -= lastbit(l));
        return ans;
    }
    inline int lastbit(int x) {
        return x & (-x);
    }
};

const long long MOD = 1000000007;
void solve() {
    int R, C, K; cin >> R >> C >> K;
    vector<vector<int>> g(R+1, vector<int> (C+1, 0));
    for (int i=1; i<=R; i++)
        for (int j=1; j<=C; j++)
            cin >> g[i][j], --g[i][j];

    vector<vector<int>> dp(R+1, vector<int> (C+1, 0));
    vector<vector<int>> prefG(R+2, vector<int> (C+2, 0));

    /* BIT<R, C> b[K]; */
    /* BIT<R, C> bMaj; */
    /* for (int i=1; i<=R; i++) { */
    /*     for (int j=1; j<=C; j++) { */
    /*         prefG[i][j] = g[i][j] */
    /*             + prefG[i-1][j] */
    /*             + prefG[i][j-1] */
    /*             - prefG[i-1][j-1]; */
    /*     } */
	/* } */
    /* int initC = g[0][0]; */
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            int sum = prefG[i-1][j-1];
            dp[i][j] = sum;

            prefG[i][j] = dp[i][j]
                + prefG[i-1][j]
                + prefG[i][j-1]
                - prefG[i-1][j-1];
        }
    }

    cout << dp[R][C] << endl;
    for (auto i : dp) {
        for (auto j : i)
            cout << j << " ";
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
// Sum up all the values that are above x, y with Ans segtree
// We can find the number of same values with the T segtree
//
// It should be the Ans segtree minus the T segtree
// Every time we compute the d[x][y] of a value, we can update the T segtree

// Solution: We need to maintain one segment tree for each column for each color
// Sum up all the values that can jump to that one with DP.
// dp[x][y] is the sum of all the values that can arrive at point (x, y)
// Note: Might be easier with a BIT

// 1 1 3 2 4 1
// Feels like dp + segment tree
// Find how many ways you can reach from here. Sum it up and get answer
// How do we make sure that we don't include the values that have the same one as the current node
//
// Naive
// Iterate through the whole subrectangle, will take RC per subrectangle
// Will then iterate through all the squares and sum it up that way
// R^4 with R = 750
//
// Need time complexity of
// N^2logN or N^2 (logN)^2
// Run one or two segtree queries
//
// What if we update the query function so that it doesn't include another argument x
// Two ways we can not include same letter:
// - NOT We can either just make it not included when we sum up the segment
// - We can have it not included in the segment tree
// Use an order statistic tree...
// Count the number of sames in the subrect and subtract
// Subtract the sum of the sames - iterate over the sames and subtract
//
// Complementary counting:
// Get all values
// Then sum up the amount of values where there are jumps from same values
// How do we sum up the ones that have jumps between same values...
//
// It's a graph problem
// There's no point in constructing a graph
