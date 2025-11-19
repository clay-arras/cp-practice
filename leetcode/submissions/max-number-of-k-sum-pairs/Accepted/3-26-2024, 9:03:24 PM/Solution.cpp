// https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int l=0, r=(int)nums.size()-1; l<r;) {
            if (nums[l] + nums[r] == k) {
                count++;
                l++, r--;
            } else if (nums[l] + nums[r] > k) {
                r--;
            } else {
                l++;
            }
        }
        return count;
    }
};