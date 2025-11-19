// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    const static int OFFSET = 1e4+1;
    int findKthLargest(vector<int>& nums, int k) {
        for (auto& i : nums)
            i += OFFSET;

        int mxV = *max_element(nums.begin(), nums.end());
        int N = (int)nums.size();

        vector<int> cnt(mxV+1, 0);
        for (int i : nums)
            cnt[i]++;

        int count = 0;
        for (int i=mxV; i>=0; i--) {
            count += cnt[i];
            if (count >= k) 
                return i - OFFSET;
        }
        return -1;
    }
};