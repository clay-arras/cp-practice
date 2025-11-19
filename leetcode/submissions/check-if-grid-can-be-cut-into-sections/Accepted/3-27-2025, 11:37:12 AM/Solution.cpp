// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // ideas/algorithms: 
        // - prefix sum or SOMEHOW segment tree/BIT
        // - line sweep
        
        // simplifying the problem: 
        // assume ONLY vertical lines are valid
        // slow: check every pair of lines at each "critical point"
        // maybe see them as intervals instead 

        // algo: line sweep on constructed INTERVALS
        vector<vector<int>> test2;
        for (auto i : rectangles) {
            test2.push_back({i[0], i[2]});
        }

        vector<pair<int, int>> ints;
        for (auto i : test2) {
            ints.push_back({i[0], 1}); 
            ints.push_back({i[1], -1});
        }
        sort(ints.begin(), ints.end());
        
        int count = 0;
        int ans = -1;
        for (auto i : ints) {
            count += i.second;
            if (!count) 
                ans++;
        }
        if (ans >= 2)
            return true;

        vector<vector<int>> test1;
        for (auto i : rectangles) {
            test1.push_back({i[1], i[3]});
        }

        ints.clear();
        for (auto i : test1) {
            ints.push_back({i[0], 1}); 
            ints.push_back({i[1], -1});
        }
        sort(ints.begin(), ints.end());
        
        count = 0;
        ans = -1;
        for (auto i : ints) {
            count += i.second;
            if (!count) 
                ans++;
        }
        if (ans >= 2)
            return true;
        return false;
    }
};