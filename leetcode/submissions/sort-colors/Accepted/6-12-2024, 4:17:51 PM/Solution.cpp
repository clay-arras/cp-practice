// https://leetcode.com/problems/sort-colors

class Solution {
public:
    int count[3];
    void sortColors(vector<int>& nums) {
        for (int i : nums)
            count[i]++;
        
        for (int i=0; i<(int)nums.size(); i++) {
            if (i < count[0]) nums[i] = 0;
            else if (i < count[0] + count[1]) nums[i] = 1;
            else if (i < count[0] + count[1] + count[2]) nums[i] = 2;
        }
    }
};