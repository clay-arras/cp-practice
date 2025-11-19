// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    const static int MAXN = 1e3 + 4;
    const static int MOD = 1e9 + 7;
    int dp[MAXN][2];

    int numTilings(int n) {
        dp[1][0] = 1;
        dp[2][0] = 2;
        dp[1][1] = 1;

        for (int i=1; i<=n; i++) {
            dp[i+1][1] = (dp[i+1][1] + dp[i][1]) % MOD;
            dp[i+2][0] = (dp[i+2][0] + dp[i][1]) % MOD;
            dp[i+1][0] = (dp[i+1][0] + dp[i][0]) % MOD;
            dp[i+2][0] = (dp[i+2][0] + 2*dp[i][0]) % MOD;
            dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % MOD;
        }
        for (int i=0; i<=n; i++) {
            cout << dp[i][0] << " ";
        }
        cout << endl;
        for (int i=0; i<=n; i++) {
            cout << dp[i][1] << " ";
        }
        cout << endl;
        return dp[n][1];
    }
};