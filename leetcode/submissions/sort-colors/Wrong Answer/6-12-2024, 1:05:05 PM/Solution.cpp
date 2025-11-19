// https://leetcode.com/problems/sort-colors

class Solution {
public:
    int count[3], pnt[3];
    void sortColors(vector<int>& nums) {
        for (int i : nums)
            count[i]++;
        
        pnt[0] = 0;
        pnt[1] = count[0];
        pnt[2] = count[0] + count[1];
        for (int i=0; i<(int)nums.size(); i++) {
            while (i < pnt[nums[i]] && pnt[nums[i]] < (int)nums.size()) {
                swap(nums[i], nums[pnt[nums[i]]]);
                pnt[nums[i]]++;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};