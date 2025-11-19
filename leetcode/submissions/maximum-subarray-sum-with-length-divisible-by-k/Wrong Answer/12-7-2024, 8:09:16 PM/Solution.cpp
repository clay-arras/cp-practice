// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();
        vector<long long> pref(N+1, 0);
        for (int i=1; i<=N; i++) 
            pref[i] = pref[i-1] + nums[i-1];

        long long ans = LLONG_MIN;
        for (int s=0; s<k; s++) {
            long long curr = -1e14;
            for (int i=s; i+k<=N; i+=k) {
                long long num = pref[i+k] - pref[i];
                curr = max(num, curr + num);       
                ans = max(ans, curr);
            }
            ans = max(ans, curr);
        }

        for (auto i : pref)
            cout << i << " ";
        cout << endl;
        
        return ans;
    }
};