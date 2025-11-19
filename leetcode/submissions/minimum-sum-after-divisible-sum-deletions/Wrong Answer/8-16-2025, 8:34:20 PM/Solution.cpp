// https://leetcode.com/problems/minimum-sum-after-divisible-sum-deletions

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        // dp? 
        // feels like a stack esque type of problem, where if any PREFIX of the previous values is divisible by k then we REMOVE the whole prefix (pop until we hit that prefix)

        int N = (int)nums.size();
        vector<int> pref(N+1, 0);
        for (int i=1; i<=N; i++) {
            pref[i] = pref[i-1] + nums[i-1];
        }
        vector<int> mod(k, INT_MAX), dp(N, INT_MAX);

        dp[0] = (nums[0] % k ? nums[0] : 0);
        mod[pref[1]%k] = 0;
        for (int i=1; i<N; i++) {
            dp[i] = dp[i-1] + nums[i]; 
            if (pref[i+1]%k == 0) {
                dp[i] = 0;
                continue;
            }
                
            int idx = mod[pref[i+1]%k];
            if (idx != INT_MAX) {
                dp[i] = min(dp[i], dp[i-idx]);
            }
            mod[pref[i+1]%k] = min(i, mod[pref[i+1]%k]);
        }

        return dp[N-1];
    }
};