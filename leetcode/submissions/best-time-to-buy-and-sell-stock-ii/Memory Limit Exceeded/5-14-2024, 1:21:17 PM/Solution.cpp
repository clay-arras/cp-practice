// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = (int)prices.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

        for (int i=0; i<N; i++) {
            for (int j=0; j<=i; j++) {
                dp[i+1][i] = max(dp[i+1][i], dp[i][j] + (prices[i] - prices[j]));
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
            }
        }

        return dp[N][N];
    }
};