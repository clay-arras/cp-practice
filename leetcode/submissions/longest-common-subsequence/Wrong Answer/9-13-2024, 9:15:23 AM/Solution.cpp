// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = (int)text1.size();
        int M = (int)text2.size();

        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(2, 0)));
        for (int i=0; i<=N; i++) {
            for (int j=0; j<=M; j++) {
                if (i) dp[i][j][0] = max(dp[i][j][0], max(dp[i-1][j][0], dp[i-1][j][1]));
                if (j) dp[i][j][0] = max(dp[i][j][0], max(dp[i][j-1][0], dp[i][j-1][1]));
                if (i && j && text1[i-1] == text2[j-1]) {
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][0] + 1);
                    dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0] + 1);
                }
            }
        }
        return max(dp[N][M][0], dp[N][M][1]);
    }
};