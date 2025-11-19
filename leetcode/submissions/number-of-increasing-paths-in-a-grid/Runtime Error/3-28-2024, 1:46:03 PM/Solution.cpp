// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid

class Solution {
public:
    const static int MAXN = 1e3+4;
    int dp[MAXN][MAXN];

    int countPaths(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>> pq;

        int M = (int)grid[0].size(), N = (int)grid.size();
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                pq.push({-grid[i][j], {i, j}});
        
        while (!pq.empty()) {
            int val = -pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            dp[i][j] = 1;
            if (i - 1 >= 0 && val > grid[i-1][j])
                dp[i][j] += dp[i-1][j];
            if (j - 1 >= 0 && val > grid[i][j-1])
                dp[i][j] += dp[i][j-1];
            if (i + 1 < N && val > grid[i+1][j])
                dp[i][j] += dp[i+1][j];
            if (j + 1 < M && val > grid[i][j+1])
                dp[i][j] += dp[i][j+1];
        }
        int ans = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                ans += dp[i][j];
                
        return ans;
    }
};