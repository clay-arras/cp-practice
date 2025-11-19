// https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions

class Solution {
public:
    const static int ID = 1e9;

    int minimumOperations(vector<vector<int>>& grid) {
        // pattern: precalculate + dp
        // dp[i][chosen value] = num ops
        int N = (int)grid.size(), M = (int)grid[0].size();

        // vector<map<int, int>> cnt(N);
        // for (int i=0; i<N; i++) {
        //     cnt[i][ID + i] = 0; // stub id
        //     for (auto j : grid[i])
        //         cnt[i][j]++; // might be easier to just use a vector and sort it. 
        // }
        vector<vector<int>> dp(M, vector<int>(3, INT_MAX));
        for (int i=0; i<M; i++) {
            for (int k=0; k<3; k++) {
                for (auto it=cnt[i].rbegin(); it!=cnt[i].rend(); ++it) { // it is the largest
                    if (!i && it->first == (cnt[i-1].begin() + k)->first) 
                        continue;

                    if (i) 
                        dp[i][k] = dp[i-1][it - cnt[i].rbegin]
                    dp[i][k] += N - it->second;
                }
            }
        }
        int ans = INT_MAX;
        for (int i=0; i<3; i++)
            ans = min(ans, dp[M-1][i]);

        return ans;
    }
};