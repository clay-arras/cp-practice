#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long INF = 1e18+69;
void solve() {
    int N, K; cin >> N >> K;

    deque<int> R;
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        R.push_back(t);
    }

    long long ans = INF;
    for (int j=0; j<N; j++) {
        vector<vector<long long>> dp(K+10, vector<long long>(N+10, INF));
        dp[0][N] = 0;

        // We put the kth door at j
        for (int k=1; k<=K; k++) {
            for (int i=0; i<N; i++) {
                long long sum = 0;

                for (int c=i+1; c<=N; c++) {
                    sum += R[c-1] * (c - i - 1);
                    long long dist = dp[k-1][c];

                    if (dist != INF)
                        dist += sum;
                    dp[k][i] = min(dp[k][i], dist);
                }
            }
        }
        ans = min(ans, dp[K][0]);

        int t = R.front();
        R.pop_front();
        R.push_back(t);
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

// DP
// - One variable is the location of the starting door. We just iterate through N and place it at that value
// - The second variable is the how many K's we have up to this point
// - The third variable is the value that we are iterating on
// - The total time complexity should be N^2 K
//
// dp[starting door][it][k]
// Some are impossible so we initialize the vector<vector<vector<int>>> dp
// (N, vector<vector<int>>(N, vector<int>(K, -1)));
//
// Do we loop through backwards...
//
// We can just rotate the array after every iteration...
// Or we can use MINT.. lets use modInt
//
// For every one after the starting door we just add
// - The distance from the previous door (we can just keep that in a variable)
// - And the number of cows in the cell that we are on
// Need some clever backtracking so that we can find the sumCows before setting the next door
/* // - Set the i => (j, N+j) loop to go backwards */

// Do we iterate through K backwards...
// dp[j][i][1] = 0
//
// Solution: don't need a dimension for the dp
// We can just use a queue or similar
// Problem: the barn is circular:
// Solution: fix the first door of the barn and use a deque to cycle through possible positions
// Time: O(N)
//
// Tips:
// Constant values can be excluded from DP array
//
// Find all the positions that we could have set the door previously, that are k-1
// How do we keep a consistent sumCows

// dp[j][i][k] = min(dp[j][i][k], dp[j][i-c][k-1] + sumCows)
// int sumCows = 0;
// for (int c=i; c>=i-N; c--)
// int ct=(c+N)%N;
// sumCows +=
