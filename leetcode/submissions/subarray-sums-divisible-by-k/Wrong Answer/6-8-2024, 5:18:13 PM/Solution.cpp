// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int N = (int)nums.size();
        vector<int> pref(N+1, 0);
        for (int i=0; i<N; i++) 
            pref[i+1] += pref[i] + nums[i];

        int ans = 0;
        map<int, int> m;
        for (int i=1; i<=N; i++) {
            m[pref[i-1]%k]++;
            if (m[pref[i]%k]) 
                ans += m[pref[i] % k];
        }

        return ans;        
    }
};