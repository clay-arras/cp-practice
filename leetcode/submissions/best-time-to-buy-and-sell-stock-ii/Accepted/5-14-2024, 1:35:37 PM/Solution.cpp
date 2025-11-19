// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = (int)prices.size();
        vector<int> dp(N+1, 0);

        int minVal = INT_MAX;
        for (int i=0; i<N; i++) {
            minVal = min(minVal, prices[i]);
            dp[i+1] = dp[i];
            int val = prices[i] - minVal;
            if (val > 0) {
                minVal = prices[i];
                dp[i+1] += val;
            }
        }

        return dp[N];
    }
};
/*
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 
0 0 4 4 0 0 0 0 0 0 0 0 
0 0 4 4 4 0 0 0 0 0 0 0 
0 0 4 4 7 7 0 0 0 0 0 0 
0 0 4 4 7 7 7 0 0 0 0 0 
0 0 4 4 7 7 7 7 0 0 0 0 
0 0 4 4 7 7 7 8 8 0 0 0 
0 0 4 4 7 7 7 8 11 11 0 0 
0 0 4 4 7 7 7 8 11 11 11 0 
0 0 4 4 7 7 7 8 11 11 12 12 



*/