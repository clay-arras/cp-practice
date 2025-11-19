// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int numTilings(int n) {
        int MOD = 1e9 + 7;
        vector<int> dp(n+2, 1);
        dp[2] = 2;
        for (int i=3; i<=n; i++) 
            dp[i] = (2*dp[i-1] % MOD + dp[i-3] % MOD) % MOD;
        return dp[n];
    }
};