#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// If you make a cut for a block the size, then you have four seperate subsegments to account for
// dp = the minimum amount of block size wasted, or the maximum amount of block size that can be obtained.
// Recursive dp: you have to iterate through all the possible cuts for each state and return the amount of size that can be gained through that

// If the block is the size for a desired block, return 0 (no space wasted) or return the dimensions of that block (all space filled)
// If the block is a 1x1 block or the like, then we compare that and see if there are any blocks that size. If not, then we just return

// dp[i][j] = space wasted

vector<vector<int>> dp;
vector<vector<bool>> visited;

/* int recDP(int i, int j){ */
/*     if (visited[i][j]) */
/*         return dp[i][j]; */

/*     int mxV = 0; */
/*     for (int it=1; it<i; it++) */
/*         mxV = max(mxV, recDP(it, j) + recDP(i-it, j)); */
/*     for (int jt=1; jt<j; jt++) */
/*         mxV = max(mxV, recDP(i, jt) + recDP(i, j-jt)); */

/*     visited[i][j] = true; */
/*     dp[i][j] = mxV; */

/*     return dp[i][j]; */
/* } */

// NOTE: Recursive solution was too slow

void solve(){
    int W, H, N; cin >> W >> H >> N;
    dp = vector<vector<int>>(W+10, vector<int> (H+10, 0));
    visited = vector<vector<bool>>(W+10, vector<bool> (H+10, false));

    for (int i=0; i<N; i++){
        int w, h; cin >> w >> h;
        dp[w][h] = w * h;
        visited[w][h] = true;
    }

    for (int w=1; w<=W; w++){
        for (int h=1; h<=H; h++){
            for (int i=1; i<w; i++){
                dp[w][h] = max(dp[w][h], dp[i][h] + dp[w-i][h]);
            }
            for (int j=1; j<h; j++){
                dp[w][h] = max(dp[w][h], dp[w][j] + dp[w][h-j]);
            }
        }
    }

    cout << W*H - dp[W][H] << endl;
    /* cout << W*H - recDP(W, H) << endl; */
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
