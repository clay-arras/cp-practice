// https://leetcode.com/problems/maximum-alternating-sum-of-squares

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int N = (int)nums.size();
        for (int i=0; i<N; i++)
            nums[i] = nums[i] * nums[i];
        sort(nums.rbegin(), nums.rend());

        long long ans = 0;
        for (int i=0; i<N; i++) {
            if (i < ceil(N*1.0/2))
                ans += nums[i];
            else 
                ans -= nums[i];
        }

        return ans;
    }
};