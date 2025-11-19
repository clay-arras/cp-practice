// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for (int i=0; i<(int)nums.size(); i++) {
            m[nums[i]]++;
            if (m[nums[i]] > 1)
                return true;
        }
        return false;
    }
};