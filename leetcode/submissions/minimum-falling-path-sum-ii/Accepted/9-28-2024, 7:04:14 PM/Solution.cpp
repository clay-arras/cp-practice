// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int N = (int)grid.size();
        vector<vector<pair<int, int>>> minVals(N, vector<pair<int, int>>(2, {INT_MAX, 0}));
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                dp[i][j] = grid[i][j];

                if (i-1 >= 0 && minVals[i-1][0].second != j) {
                    dp[i][j] += minVals[i-1][0].first;
                } else if (i-1 >= 0) {
                    dp[i][j] += minVals[i-1][1].first;
                }

                pair<int, int> t = {dp[i][j], j};
                if (minVals[i][0] > t) {
                    minVals[i][1] = minVals[i][0];
                    minVals[i][0] = t;
                } else if (minVals[i][1] > t) {
                    minVals[i][1] = t;
                }
            }
        }

        return minVals[N-1][0].first;
    }
};
