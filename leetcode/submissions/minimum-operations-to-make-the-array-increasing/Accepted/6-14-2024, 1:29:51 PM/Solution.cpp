// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = (int)nums.size();
        int ans = 0;
        for (int i=1; i<N; i++) {
            int val = max(nums[i-1] - nums[i] + 1, 0);
            ans += val;
            nums[i] += val;
        }
        return ans; 
    }
};