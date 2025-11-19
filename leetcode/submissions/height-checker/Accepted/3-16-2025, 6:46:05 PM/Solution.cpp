// https://leetcode.com/problems/height-checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights);
        sort(expected.begin(), expected.end());
        int N = (int)heights.size();
        
        int ans = 0;
        for (int i=0; i<N; i++) {
            if (heights[i] != expected[i])
                ans++;
        }
        return ans;
    }
};