// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> s = heights;
        sort(s.begin(), s.end());

        int ans = 0;
        for (int i=0; i<(int)s.size(); i++)
            if (s[i] != heights[i]) ans++;

        return ans;
    }
};