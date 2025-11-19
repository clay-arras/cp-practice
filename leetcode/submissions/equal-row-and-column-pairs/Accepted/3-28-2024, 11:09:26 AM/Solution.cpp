// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> m;
        int N = (int)grid.size();

        for (int i=0; i<N; i++) {
            vector<int> arr;
            for (int j=0; j<N; j++) {
                arr.push_back(grid[j][i]);
            }
            m[arr]++;
        }
        int count = 0;
        for (int i=0; i<N; i++) {
            if (m[grid[i]])
                count += m[grid[i]];
        }
        return count;
    }
};