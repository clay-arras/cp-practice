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
            cnt[i][-(ID + i)] = 1; // stub id
            cnt[i][-(2*ID + i)] = 1; // stub id
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

        vector<vector<int>> dp(M, vector<int>(3, INT_MAX));
        dp[0][0] = N - mp[0][0].first;
        dp[0][1] = N - mp[0][1].first;
        dp[0][2] = N - mp[0][2].first;

        for (int i=1; i<M; i++) {
            for (int k=0; k<3; k++) { // 0 is the biggest
                for (int t=0; t<3; t++) {
                    if (mp[i][k].second != mp[i-1][t].second) {
                        dp[i][k] = dp[i-1][t] + (N - mp[i][k].first);
                        break;
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i=0; i<3; i++)
            ans = min(ans, dp[M-1][i]);
        return ans;
    }
};

/*

[[1,9,1,6],
 [3,8,1,3],
 [8,2,9,1],
 [8,3,9,4]]

3 + 2 + 3 + 2
*/