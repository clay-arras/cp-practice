// https://leetcode.com/problems/stone-game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = (int)piles.size();
        vector<vector<int>> dp (N, vector<int>(N, 0));
        for (int l=0; l<N; l++) {
            for (int r=N-1; r>l; r--) {
                if ((r-l) % 2) dp[l][r] = -INT_MAX;
                else dp[l][r] = INT_MAX;
            }
        }
        dp[0][N-1] = 0;
        for (int l=0; l<N; l++) {
            for (int r=N-1; r>=l; r--) {
                if ((r-l) % 2) { // Alice
                    if (l-1 >= 0) dp[l][r] = max(dp[l][r], dp[l-1][r] + piles[l-1]);
                    if (r+1 < N) dp[l][r] = max(dp[l][r], dp[l][r+1] + piles[r+1]);
                } else { // Bob
                    if (l-1 >= 0) dp[l][r] = min(dp[l][r], dp[l-1][r] + piles[l-1]);
                    if (r+1 < N) dp[l][r] = min(dp[l][r], dp[l][r+1] + piles[r+1]);
                }
            }
        }
        bool ans = false;
        for (int i=0; i<N; i++)    
            ans |= (dp[i][i] > 0);
        return ans;
    }
};