// https://leetcode.com/problems/house-robber

class Solution {
public:
    const static int MAXN = 1e2 + 1;
    int dp[MAXN];
    int rob(vector<int>& nums) {
        int N = (int)nums.size();

        if (N == 1) {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i=0; i<N; i++) {
            if (i-3 >= 0)
                dp[i] = max(dp[i-1], dp[i-3] + nums[i]);
            if (i-2 >= 0)
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        for (auto i : dp) 
            cout << i << " ";
        cout << endl;
        return dp[N-1];
    }
};