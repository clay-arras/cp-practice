// https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions

class Solution {
public:
    const static int ID = 1e7;

    int minimumOperations(vector<vector<int>>& grid) {
        // pattern: precalculate + dp
        // dp[i][chosen value] = num ops
        int N = (int)grid.size(), M = (int)grid[0].size();

        vector<unordered_map<int, int>> cnt(M);
        for (int i=0; i<M; i++) {
            cnt[i][(ID + i)] = 0; // stub id
            for (int j=0; j<N; j++)
                cnt[i][grid[j][i]]++; 
        }

        vector<vector<pair<int, int>>> mp(M);
        for (int i=0; i<M; i++) {
            for (auto [k, v] : cnt[i]) {
                mp[i].push_back({v, k});
            }
            sort(mp[i].rbegin(), mp[i].rend());
        }

        vector<vector<int>> dp(M, vector<int>(N+1, INT_MAX));
        for (int i=0; i<mp[0].size(); i++)
            dp[0][i] = N - mp[0][i].first;

        for (int i=1; i<M; i++) {
            for (int k=0; k<mp[i].size(); k++) { // 0 is the biggest
                for (int t=0; t<mp[i-1].size(); t++) {
                    if (mp[i][k].second != mp[i-1][t].second) {
                        dp[i][k] = min(dp[i][k], dp[i-1][t] + (N - mp[i][k].first));
                        // break;
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i=0; i<N+1; i++)
            ans = min(ans, dp[M-1][i]);
        return ans;
    }
};

/*

[[1,9,1,6],
 [3,8,1,3],
 [8,2,9,1],
 [8,3,9,4]]

2 + 3 + 2 + 3
*/