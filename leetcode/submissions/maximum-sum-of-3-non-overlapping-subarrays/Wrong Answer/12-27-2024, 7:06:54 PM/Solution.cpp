// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = (int)nums.size();
        vector<int> pref(N-k+1, 0);

        int sum = 0;
        for (int i=0; i<N; i++) {
            sum += nums[i];
            if (i >= k-1) {
                pref[i-k+1] = sum;
                sum -= nums[i-k+1];
            }
        }
        // dp[i][k] means starting at the ith index and having already done k 
        // trans: dp[i+k][j-1] = max(dp[i+k][j-1], dp[i][j] + pref[i])
        vector<vector<int>> dp(N-k+1, vector<int> (3, 0));
        for (int i=0; i<N-k+1; i++) {
            for (int j=0; j<3; j++) {
                
            }
        }
        cout << dp[N-k][2] << endl;


        return {};
    }
};