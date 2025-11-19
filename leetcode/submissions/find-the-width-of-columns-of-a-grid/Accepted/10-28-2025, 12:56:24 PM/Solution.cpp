// https://leetcode.com/problems/find-the-width-of-columns-of-a-grid

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int M = (int)grid.size(), N = (int)grid[0].size();
        vector<int> ans(N);
        for (int i=0; i<N; i++) {
            int mx = 0;
            for (int j=0; j<M; j++)
                mx = max(mx, (int)to_string(grid[j][i]).size());
            ans[i] = mx;
        }

        return ans;
    }
};