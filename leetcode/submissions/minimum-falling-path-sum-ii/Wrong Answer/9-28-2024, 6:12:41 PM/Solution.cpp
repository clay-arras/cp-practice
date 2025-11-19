// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // sort with min_val + index
        // store minVal and secondMinVal
        int N = (int)grid.size(), M = (int)grid[0].size();
        vector<vector<pair<int, int>>> minVals(N, vector<pair<int, int>>(2, {INT_MAX, INT_MAX}));
        vector<vector<int>> dp(N, vector<int>(M, INT_MAX));

        // for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                pair<int, int> t = {grid[0][j], j};
                if (minVals[0][0] > t)        
                    minVals[0][0] = t;
                else if (minVals[0][1] > t)        
                    minVals[0][1] = t;
            }
        // }

        for (int i=0; i<N; i++)
            cout << minVals[i][0].first << "," << minVals[i][0].second << "  " << minVals[i][1].first << "," << minVals[i][1].second << endl;

        for (int i=0; i<M; i++)
            dp[0][i] = grid[0][i];

        for (int i=1; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (minVals[i-1][0].second == j) {
                    dp[i][j] = minVals[i-1][1].first;
                } else {
                    dp[i][j] = minVals[i-1][0].first;
                }
                dp[i][j] += grid[i][j];

                pair<int, int> t = {dp[i][j], j};
                if (minVals[i][0] > t)        
                    minVals[i][0] = t;
                else if (minVals[i][1] > t)        
                    minVals[i][1] = t;
            }
        }

        int ans = INT_MAX;
        for (int i=0; i<M; i++)
            ans = min(ans, dp[N-1][i]);
        return ans;
    }
};
