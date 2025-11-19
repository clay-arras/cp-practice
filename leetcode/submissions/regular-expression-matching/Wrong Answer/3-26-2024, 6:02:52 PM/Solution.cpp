// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    const static int MXN = 2e1 + 2;
    int dp[MXN][MXN];
    
    bool isMatch(string s, string p) {

        int M = (int)s.size();
        int N = (int)p.size();

        s = ";" + s;
        p = ":" + p;

        dp[0][0] = 1;
        // dp[0][1] = 1;
        for (int i=0; i<=M; i++) 
            cout << i << " " << s[i] << endl;
        cout << endl;

        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                if (p[i] == '*') {
                    if (j == 1 && i == 2)
                        dp[i][j] == 1;

                    dp[i][j] |= dp[i-2][j];
                    dp[i][j] |= (dp[i-1][j] | dp[i][j-1]) &
                            (p[i-1] == s[j] | p[i-1] == '.');
                    // cout << p[i-1] << "X" << s[j] << endl;
                } else if (p[i] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] & (p[i] == s[j]);
                }
            }
        }

        for (int i=0; i<=N; i++) {
            for (int j=0; j<=M; j++)
                cout << dp[i][j];
            cout << endl;
        }

        return dp[N][M];
    }
};