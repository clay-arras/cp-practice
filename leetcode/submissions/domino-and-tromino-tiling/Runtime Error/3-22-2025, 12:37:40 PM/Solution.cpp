// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int numTilings(int n) {
        vector<int> dp(n+2, 1);
        dp[2] = 2;
        for (int i=3; i<=n; i++) 
            dp[i] = 2*dp[i-1] + dp[i-3];
        return dp[n];
    }
};