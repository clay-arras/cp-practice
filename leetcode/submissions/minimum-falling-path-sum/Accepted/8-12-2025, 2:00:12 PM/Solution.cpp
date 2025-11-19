// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int MXV = 2e9+9;
        int N = (int)matrix.size();
        
        vector<vector<int>> dp(N, vector<int>(N, MXV));
        for (int i=0; i<N; i++)
            dp[0][i] = matrix[0][i];
        for (int i=1; i<N; i++) {
            for (int j=0; j<N; j++) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + matrix[i][j]);
                if (j+1 < N)
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1] + matrix[i][j]);
                if (j-1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + matrix[i][j]);
            }
        }
        int ans = MXV;
        for (int i=0; i<N; i++)
            ans = min(ans, dp[N-1][i]);
        return ans;
    }
};