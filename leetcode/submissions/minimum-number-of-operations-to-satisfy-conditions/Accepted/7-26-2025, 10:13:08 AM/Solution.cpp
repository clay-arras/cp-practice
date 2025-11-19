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

        vector<vector<int>> dp(M, vector<int>(N+1, 1e9));
        pair<int, int> fb = {1e9, 1e9}, sb = {1e9, 1e9};
        for (int k=0; k<mp[0].size(); k++) {
            dp[0][k] = N - mp[0][k].first;
            pair<int, int> curr{dp[0][k], mp[0][k].second};
            if (fb > curr) {
                sb = fb;
                fb = curr;
            } else {
                sb = min(sb, curr);
            }
        }

        for (int i=1; i<M; i++) {
            for (int k=0; k<mp[i].size(); k++) {
                if (mp[i][k].second != fb.second) {
                    dp[i][k] = min(dp[i][k], fb.first + (N - mp[i][k].first));
                }
                if (mp[i][k].second != sb.second) {
                    dp[i][k] = min(dp[i][k], sb.first + (N - mp[i][k].first));
                }
            }
            fb = {1e9, 1e9};
            sb = {1e9, 1e9};
            for (int k=0; k<mp[i].size(); k++) { 
                pair<int, int> curr{dp[i][k], mp[i][k].second};
                if (fb > curr) {
                    sb = fb;
                    fb = curr;
                } else {
                    sb = min(sb, curr);
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i=0; i<N+1; i++)
            ans = min(ans, dp[M-1][i]);
        return ans;
    }
};