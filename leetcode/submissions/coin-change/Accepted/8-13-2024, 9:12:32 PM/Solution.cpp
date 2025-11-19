// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i : coins)
            if (i <= amount)
                dp[i] = 1;
        
        for (int i=0; i<=amount; i++) 
            for (int j : coins) 
                if (i-j >= 0 && dp[i-j] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-j] + 1);
        
        return (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
};