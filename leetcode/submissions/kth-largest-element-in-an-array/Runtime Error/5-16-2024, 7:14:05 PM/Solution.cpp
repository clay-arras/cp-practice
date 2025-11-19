// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int mxV = *max_element(nums.begin(), nums.end());
        int N = (int)nums.size();

        vector<int> cnt(mxV+1, 0);
        for (int i : nums)
            cnt[i]++;

        int count = 0;
        for (int i=mxV; i>=0; i--) {
            count += cnt[i];
            if (count >= k) 
                return i;
        }
        return -1;
    }
};