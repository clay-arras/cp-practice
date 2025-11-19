// https://leetcode.com/problems/find-the-maximum-sum-of-node-values

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int N = (int)nums.size();
        vector<vector<int>> adj_list(N);
        vector<int> dp(N+1, 0);

        for (auto i : edges) {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }

        for (int i=1; i<=N; i++) {
            dp[i] = dp[i-1] + nums[i-1];
            for (int j : adj_list[i-1]) {
                if (i-1 > j) continue;
                dp[i] += nums[j];
                if (dp[i] < dp[i-1] + (nums[i-1]^k) - nums[j] + (nums[j]^k)) {
                    dp[i] = dp[i-1] + (nums[i-1]^k) - nums[j] + (nums[j]^k);
                    nums[i-1] ^= k;
                    nums[j] ^= k;
                }
            }
        }
        return dp[N];
    }
};
