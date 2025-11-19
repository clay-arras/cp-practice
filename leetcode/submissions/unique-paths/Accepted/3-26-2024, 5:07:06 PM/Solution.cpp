// https://leetcode.com/problems/unique-paths

class Solution {
public:
    const static int MAXN = 1e2 + 4;
    int dp[MAXN][MAXN];
    int uniquePaths(int m, int n) {

        dp[1][1] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (i != 1 || j != 1)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};