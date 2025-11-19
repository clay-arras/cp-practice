// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = (int)nums.size();
        int sum = 0;

        int ans = nums[0];
        for (int r=0; r<N; r++) {
            if (sum < 0) sum = 0;
            sum += nums[r];
            ans = max(ans, sum);
        }
        return ans;
    }
};