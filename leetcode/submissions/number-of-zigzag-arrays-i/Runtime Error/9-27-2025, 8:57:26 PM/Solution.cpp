// https://leetcode.com/problems/number-of-zigzag-arrays-i

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9+7;
        int d = r - l + 1;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(d, vector<int>(2, 0)));
        for (int j=0; j<d; j++) {
            dp[1][j][0] = d-j-1;
            dp[1][j][1] = j;
        }

        for (int i=1; i<n-1; i++) {
            for (int j=0; j<d; j++) {
                bool b = true;
                for (int k=0; k<=j-1; k++) {
                    if (k < d)
                        dp[i+1][k][!b] += dp[i][j][b];
                }
                
                b = false;
                for (int k=j+1; k<d; k++) {
                    if (k >= 0)
                        dp[i+1][k][!b] += dp[i][j][b];
                }
            }
        }

        for (int i=0; i<n; i++) {
            cout << setw(4);
            for (int j=0; j<d; j++) {
                cout << dp[i][j][0] << "," << dp[i][j][1] << " ";
            }
            cout << endl;
        }

        int sum = 0;
        for (int j=0; j<d; j++) 
            sum += dp[n-1][j][0] + dp[n-1][j][1];
        return sum;
    }
};