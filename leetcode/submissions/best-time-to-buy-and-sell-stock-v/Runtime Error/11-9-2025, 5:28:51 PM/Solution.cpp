// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int N = (int)prices.size();
        vector<vector<int>> dp(3, vector<int>(k+1, -1e9));

        dp[0][0] = 0;
        for (int i=0; i<N; i++) {
            for (int j=k; j>=1; j--) {
                dp[0][j] = max(dp[0][j], max(dp[1][j] + prices[i], dp[2][j] - prices[i]));
                dp[1][j] = max(dp[1][j], dp[0][j-1] - prices[i]);
                dp[2][j] = max(dp[2][j], dp[0][j-1] + prices[i]);
            }
        }
        int ans = 0;
        for (int i=0; i<=k; i++)
            ans = max(ans, dp[0][i]);
        return ans;
    }
};

/*
0 = idle, 1 = buy, 2 = sell

dp[0][k] = max(dp[0][k], dp[1][k] + cost[i], dp[2][k] - cost[i]);
dp[1][k] = max(dp[1][k], dp[0][k-1] - cost[i]);
dp[2][k] = max(dp[2][k], dp[0][k-1] + cost[i]);
*/