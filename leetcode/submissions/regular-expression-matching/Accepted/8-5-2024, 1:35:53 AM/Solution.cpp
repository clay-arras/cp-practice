// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        s = '~' + s;
        p = '~' + p;
        int N = (int)p.size(); 
        int M = (int)s.size();

        vector<vector<int>> dp(N, vector<int> (M, 0));
        dp[0][0] = 1;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (p[i] == '*') {
                    dp[i][j] |= (i-2>=0 ? dp[i-2][j] : 0);
                    dp[i][j] |= (i-1>=0 ? dp[i-1][j] : 0);

                    if ((i-1>=0 && j-1>=0) && p[i-1] == '.')
                        dp[i][j] |= dp[i][j-1];
                    if ((i-1>=0 && j-1>=0) && p[i-1] != '.')
                        dp[i][j] |= dp[i][j-1] && (p[i-1] == s[j]);
                    
                } else {
                    if (p[i] == '.') 
                        dp[i][j] |= (i-1>=0 && j-1>=0 ? dp[i-1][j-1] : 0);
                    else 
                        dp[i][j] |= (i-1>=0 && j-1>=0 ? dp[i-1][j-1] : 0) && (p[i] == s[j]);
                }
            }
        }

        return dp[N-1][M-1];
    }
};