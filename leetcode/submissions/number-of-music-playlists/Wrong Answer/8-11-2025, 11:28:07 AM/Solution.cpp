// https://leetcode.com/problems/number-of-music-playlists

class Solution {
public:
    const static int MX = 1e9+7;
    int numMusicPlaylists(int n, int goal, int k) {
        // dp[i] where i is the number of songs played = number of ways
        // idea: one of those keep-information during bottom-up type-dp

         // dp[i][j] where i is the number of songs played (goal) and j is the number of songs used (n) = number of ways
         // transition: dp[i+k]

         // base case: 
         // dp[0] = 1
         // dp[1] = n;
         // dp[2] = n-1;
         // dp[3] = n-2; 
         // ...
         // dp[k] = n-(k-1)

         // dp[i] = dp[i-1] * dp[i-k]???

         // dp[goal][n] or dp[goal]
         // v k = min(n, k)
         

         // n+1 -> always new, can skip the k restriction
         // dp[i][n] = dp[i-1] * ?? + dp[i-k]???
         return 0;
    }
};