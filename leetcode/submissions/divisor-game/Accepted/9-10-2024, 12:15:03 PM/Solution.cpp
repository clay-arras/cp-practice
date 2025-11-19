// https://leetcode.com/problems/divisor-game

class Solution {
public:
    bool divisorGame(int n) {
        if (n == 1)
            return false;
        
        vector<int> dp(n+1, false);
        dp[1] = false;
        dp[2] = true;
        for (int i=1; i<n+1; i++) {
            for (int j=1; j<i; j++) 
                if (n % j == 0)
                    dp[i] |= dp[j];
        }
        return dp[n];
    }
};