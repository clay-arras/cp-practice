// https://leetcode.com/problems/minimum-sum-after-divisible-sum-deletions

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        // dp? 
        // feels like a stack esque type of problem, where if any PREFIX of the previous values is divisible by k then we REMOVE the whole prefix (pop until we hit that prefix)
        const int MXV = 2e9+9;

        int N = (int)nums.size();
        vector<int> pref(N+1, 0);
        for (int i=1; i<=N; i++) {
            pref[i] = (pref[i-1] + nums[i-1]) % k;
        }
        vector<int> mod(k, MXV), dp(N, MXV);

        dp[0] = (pref[1] % k ? nums[0] : 0);
        mod[pref[1]] = 0;
        for (int i=1; i<N; i++) {
            dp[i] = dp[i-1] + nums[i]; 
            if (pref[i+1] == 0) {
                dp[i] = 0;
                continue;
            }
                
            int idx = mod[pref[i+1]];
            if (idx != MXV) {
                dp[i] = min(dp[i], dp[idx]);
            }
            mod[pref[i+1]] = min(i, mod[pref[i+1]]);
        }
        return dp[N-1];
    }
};