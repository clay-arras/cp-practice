// https://leetcode.com/problems/maximum-path-score-in-a-grid

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int N = (int)grid.size(), M = (int)grid[0].size();
        vector<vector<vector<int>>> dp(
            N, vector<vector<int>>(M, vector<int>(k + 1, -1)));

        // dp[i][j][k] is the maximum score to get to cell (i, j) if cost is k
        dp[0][0][0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int t = 0; t <= k; t++) {
                    if (dp[i][j][t] == -1)
                        continue;

                    if (i + 1 < N && t + (bool)grid[i + 1][j] <= k) {
                        int c_i1j = (bool)grid[i + 1][j];
                        dp[i + 1][j][t + c_i1j] =
                            max(dp[i + 1][j][t + c_i1j],
                                dp[i][j][t] + grid[i + 1][j]);
                    }

                    if (j + 1 < M && t + (bool)grid[i][j + 1] <= k) {
                        int c_ij1 = (bool)grid[i][j + 1];
                        dp[i][j + 1][t + c_ij1] =
                            max(dp[i][j + 1][t + c_ij1],
                                dp[i][j][t] + grid[i][j + 1]);
                    }
                }
            }
        }

        int ans = -1;
        for (int i = 0; i <= k; i++)
            ans = max(ans, dp[N - 1][M - 1][i]);
        return ans;
    }
};