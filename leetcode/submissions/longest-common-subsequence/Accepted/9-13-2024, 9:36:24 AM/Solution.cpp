// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = (int)text1.size();
        int M = (int)text2.size();

        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (text1[i] == text2[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        return dp[N][M];
    }
};