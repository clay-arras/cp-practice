// https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays

class Solution {
public:
    vector<int> pref, costPref;
    vector<vector<int>> memo;
    int N, K;

    int dp(int st, int en) {
        if (en == N)
            return (st == N ? 0 : INT_MAX);
        if (memo[st][en] != -1)
            return memo[st][en];

        // case 1: take next element
        // dp(st, en+1);
        int exp = dp(st, en+1);

        // case 2: make into subarray
        // dp(en+1, en+1);
        int costSuf = costPref[N] - costPref[st];
        int nums = pref[en+1] - pref[st];
        int grp = (nums + K) * costSuf;
        
        int next = dp(en+1, en+1);
        grp = (next == INT_MAX ? INT_MAX : grp + next);

        return memo[st][en] = min(exp, grp);
    }

    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        N = (int)nums.size(), K = k;
        pref = vector<int> (N+1, 0); 
        costPref = vector<int> (N+1, 0); 
        
        for (int i=0; i<N; i++) {
            pref[i+1] += pref[i] + nums[i];
            costPref[i+1] += costPref[i] + cost[i];
        }

        memo = vector<vector<int>> (N+1, vector<int> (N+1, -1));
        return dp(0, 0);
    }
};
