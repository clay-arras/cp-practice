// https://leetcode.com/problems/maximize-cyclic-partition-score

class Solution {
public:
    int N, K;
    long long score(vector<int>& nums) {
        vector<vector<long long>> dp(3, vector<long long>(K+1, -1e15));
        dp[0][0] = 0;
        for (int i=0; i<N; i++) {
            for (int j=K; j>=1; j--) {
                dp[0][j] = max(dp[0][j], max(dp[1][j] - nums[i], dp[2][j] + nums[i]));
                dp[1][j] = max(dp[1][j], dp[0][j-1] + nums[i]);
                dp[2][j] = max(dp[2][j], dp[0][j-1] - nums[i]);
            }
        }
        long long ans = 0;
        for (int i=0; i<=K; i++)
            ans = max(ans, dp[0][i]);
        return ans;
    }

    long long maximumScore(vector<int>& nums, int k) {
        N = (int)nums.size(), K = k;

        int mn = *min_element(nums.begin(), nums.end());
        int mn_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx_idx = distance(nums.begin(), find(nums.rbegin(), nums.rend(), mn).base()) - 1;
        vector<int> rot;
        for (int i=0; i<2*N; i++) {
            int sz = (int)rot.size();
            if ((nums[i%N] == mn || sz) && sz < N)
                rot.push_back(nums[i%N]);
        }
        vector<int> rrot;
        for (int i=0; i<2*N; i++) {
            int sz = (int)rrot.size();
            if ((i%N == mx_idx || sz) && sz < N)
                rrot.push_back(nums[i%N]);
        }
        // for (int i : rot)
        //     cout << i << " ";
        // cout << endl;
        // for (int i : rrot)
        //     cout << i << " ";
        // cout << endl;
        // vector<int> rrot(rot.rbegin(), rot.rend());
        return max(score(rot), score(rrot));
    }
};
// 2 2 2 4 5
// 2 2 4 5 2