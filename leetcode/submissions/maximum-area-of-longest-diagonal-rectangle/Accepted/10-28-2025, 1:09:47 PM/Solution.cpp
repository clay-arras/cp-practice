// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int, int> mx = {-1, -1};
        for (auto d : dimensions) {
            mx = max(mx, {d[0] * d[0] + d[1] * d[1], d[0] * d[1]});
        }
        return mx.second;
    }
};