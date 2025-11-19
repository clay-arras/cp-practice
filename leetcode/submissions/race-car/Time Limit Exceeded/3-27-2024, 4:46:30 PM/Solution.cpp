// https://leetcode.com/problems/race-car

class Solution {
public:
    const static int DIM = 30;
    const static int MAXN = 1e6 + 4;
    const static int N = 1e4 + 4;
    int racecar(int target) {
        vector<vector<int>> dp(MAXN, vector<int>(DIM, INT_MAX));
        // (1 << i) = 2^i
        dp[0][0] = 0;
        for (int k=0; k<20; k++) {
            for (int i=0; i<N; i++) {
                for (int j=0; j<DIM; j++) {
                    if (j >= 0 && j < 13) {
                        // positive
                        if (dp[i][j] != INT_MAX) {
                            dp[i+(1 << j)][j+1] = min(dp[i+(1 << j)][j+1], dp[i][j] + 1);
                            dp[i][14] = min(dp[i][14], dp[i][j] + 1);
                        }
                    } else if (j >= 14 && j < 27) {
                        // negative
                        // j - 14 for speed
                        if (dp[i][j] != INT_MAX) {
                            if (i - (1 << (j-14)) >= 0)
                                dp[i-(1 << (j-14))][j+1] = min(dp[i-(1 << (j-14))][j+1], dp[i][j] + 1);
                            dp[i][0] = min(dp[i][0], dp[i][j] + 1);
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int i=0; i<DIM; i++) {
            ans = min(ans, dp[target][i]);
        }
        return ans;
    }
};