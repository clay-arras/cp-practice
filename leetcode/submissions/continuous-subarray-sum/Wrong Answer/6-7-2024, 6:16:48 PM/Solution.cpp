// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();
        if (N <= 1) return false;

        vector<int> pref(N+1, 0);
        for (int i=0; i<N; i++) 
            pref[i+1] += pref[i] + nums[i];

        bool ok = false;
        map<int, int> m;
        for (int i=0; i<=N; i++) {
            m[pref[i]%k]++;
            if (m[pref[i]%k] > 1) 
                ok = true;
        }

        return ok;
    }
};