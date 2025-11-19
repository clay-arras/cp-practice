// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // dp[i][j]
        // where i is the row, and j is the col, and dp[i][j] = sum

        int N = (int)grid.size(), M = (int)grid[0].size();
        vector<vector<int>> dp(N, vector<int>(M, INT_MAX));
        for (int i=0; i<M; i++)
            dp[0][i] = grid[0][i];

        for (int i=1; i<N; i++) {
            for (int j=0; j<M; j++) {
                for (int k=0; k<M; k++) {
                    if (k != j)
                        dp[i][j] = min(dp[i][j], dp[i-1][k]);
                }
                // if (j-1 >= 0)
                    // dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                // if (j+1 < M)
                    // dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                dp[i][j] += grid[i][j];

            }
        }

        int ans = INT_MAX;
        for (int i=0; i<M; i++)
            ans = min(ans, dp[N-1][i]);
        return ans;
    }
};

/*

[[-73,61,43,-48,-36]
,[ 3, 30,27, 57, 10]
,[96,-76,84, 59,-15]
,[5, -49,76, 31,-7]
,[97, 91,61,-46,67]]

*/