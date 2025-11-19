// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xs, ys;
        for (auto i : rectangles) {
            xs.push_back({i[0], 1});
            xs.push_back({i[2], -1});
            ys.push_back({i[1], 1});
            ys.push_back({i[3], -1});
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        
        int count = 0;
        int ans = -1;
        for (auto i : xs) {
            count += i.second;
            if (!count) 
                ans++;
        }
        if (ans >= 2)
            return true;

        count = 0;
        ans = -1;
        for (auto i : ys) {
            count += i.second;
            if (!count) 
                ans++;
        }
        return (ans >= 2);
    }
};