// https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays

class Solution {
public:
    vector<int> pref, costPref;

    int dp(int i, int k, )

    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        // prefix sum, dp
        // for i -> N
        // then go BACK

        // dp[i][k], we're on the ith value in the kth subarray
        // either: add i to the kth subarray, OR start a new subarray

        int N = (int)nums.size();
        pref = vector<int> (N+1, 0); 
        costPref = vector<int> (N+1, 0); 
        
        for (int i=0; i<N; i++) {
            pref[i+1] += pref[i] + nums[i];
            costPref[i+1] += costPref[i] + cost[i];
        }
        
    }
};
/*

dp[i][k] fill w/ INT_MAX
for (int i=0; i<N; i++) {
    for (int j=i; j>=1; j++) 
    
}

two ends of the dp, l and r
dp[i][k] = max(dp[i][k], dp[i-j][k-1] + (pref[i+1] + K * k) * (costPref[i+1] - costPref[i-j]); 

idea: the only variables are just i and j, we don't need to keep track of K.
two choices when processing the ith value: 
*/