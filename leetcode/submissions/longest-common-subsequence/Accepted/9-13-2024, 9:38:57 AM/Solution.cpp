// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = (int)text1.size();
        int M = (int)text2.size();

        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        for (int i=0; i<=N; i++) {
            for (int j=0; j<=M; j++) {
                if (i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if (j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if (i && j) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (text1[i-1] == text2[j-1]));
            }
        }

        return dp[N][M];
    }
};