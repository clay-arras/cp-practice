// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = "\0" + word1;
        word2 = "\0" + word2;
        int N = (int)word1.size();
        int M = (int)word2.size();

        vector<vector<int>> dp(N, vector<int>(M, INT_MAX));
        for (int i=0; i<N; i++) 
            dp[i][0] = i;
        for (int j=0; j<M; j++)
            dp[0][j] = j;

        for (int i=1; i<N; i++) {
            for (int j=1; j<M; j++) {
                
            }
        }
        
    }
};