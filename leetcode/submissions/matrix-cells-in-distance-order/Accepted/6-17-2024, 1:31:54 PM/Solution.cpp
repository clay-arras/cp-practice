// https://leetcode.com/problems/matrix-cells-in-distance-order

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                ans.push_back({i, j});

        auto dist = [&](vector<int> x) {
            return abs(x[0] - rCenter) + abs(x[1] - cCenter);
        };
        sort(ans.begin(), ans.end(), [&](const vector<int>& x, const vector<int>& y){
            return dist(x) < dist(y);
        });
        return ans;
    }
};