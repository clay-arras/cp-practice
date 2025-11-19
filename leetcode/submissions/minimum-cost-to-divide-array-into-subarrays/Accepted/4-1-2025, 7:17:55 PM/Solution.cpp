// https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays

class Solution {
public:
    vector<long long> pref, costPref;
    vector<vector<long long>> memo;
    long long N, K;

    long long dp(long long st, long long en) {
        if (en == N)
            return (st == N ? 0 : LLONG_MAX);
        if (memo[st][en] != -1)
            return memo[st][en];

        // case 1: take next element
        // dp(st, en+1);
        long long exp = dp(st, en+1);

        // case 2: make into subarray
        // dp(en+1, en+1);
        long long costSuf = costPref[N] - costPref[st];
        long long nums = pref[en+1] - pref[st];
        long long grp = (nums + K) * costSuf;
        
        long long next = dp(en+1, en+1);
        grp = (next == LLONG_MAX ? LLONG_MAX : grp + next);

        return memo[st][en] = min(exp, grp);
    }

    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        N = (int)nums.size(), K = k;
        pref = vector<long long> (N+1, 0); 
        costPref = vector<long long> (N+1, 0); 
        
        for (int i=0; i<N; i++) {
            pref[i+1] += pref[i] + nums[i];
            costPref[i+1] += costPref[i] + cost[i];
        }

        memo = vector<vector<long long>> (N+1, vector<long long> (N+1, -1));
        return dp(0, 0);
    }
};
