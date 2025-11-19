// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int cnt = 0;

        for (auto i : nums) {
            if (i == 0) cnt++;
            else ans.push_back(i);
        }
        for (int i=0; i<cnt; i++) ans.push_back(0);
        return ans;
    }
};