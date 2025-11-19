// https://leetcode.com/problems/house-robber

class Solution {
public:
    /*


    */
    
    const static int MAXN = 1e2+5;
    int dp[MAXN];
    int rob(vector<int>& nums) {
        int N = (int)nums.size();
        if (N == 1)
            return nums[0];
        if (N == 2)
            return max(nums[0], nums[1]);

        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i=2; i<N; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[N-1];
    }
};