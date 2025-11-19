// https://leetcode.com/problems/matrix-cells-in-distance-order

class Solution {
public:
    int r, c;
    struct cmp {
        bool operator()(const vector<int>& x, const vector<int>& y) const {
            return pair<int, int>({abs(x[0] - r), abs(x[1] - c)}) <
                   pair<int, int>({abs(y[0] - r), abs(y[1] - c)});
        }
    };

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                          int cCenter) {
        r = rows;
        c = cols;

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                ans.push_back({i, j});
        }
        sort(ans.begin(), ans.end(), cmp());
        return ans;
    }
};