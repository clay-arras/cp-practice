// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = (int)cost.size();
        vector<int> dp(N + 1, INT_MAX);
        cost.push_back(0);

        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i=2; i<=N; i++) {
            if (i + 2 <= N)
                dp[i+2] = min(dp[i+2], dp[i] + cost[i]);
            if (i + 1 <= N)
                dp[i+1] = min(dp[i+1], dp[i] + cost[i]);
        }
        return dp[N];
    }
};