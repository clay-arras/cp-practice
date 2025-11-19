// https://leetcode.com/problems/largest-local-values-in-a-matrix

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int N = (int)grid.size(), M = (int)grid[0].size();

        vector<vector<int>> ans;
        for (int i=1; i<N-1; i++) {
            vector<int> tmp;
            for (int j=1; j<M-1; j++) {
                tmp.push_back(max({
                    grid[i-1][j-1],
                    grid[i-1][j],
                    grid[i-1][j+1],
                    grid[i][j-1],
                    grid[i][j],
                    grid[i][j+1],
                    grid[i+1][j-1],
                    grid[i+1][j],
                    grid[i+1][j+1],
                }));
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};