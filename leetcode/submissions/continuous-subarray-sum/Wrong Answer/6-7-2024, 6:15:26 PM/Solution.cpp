// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();
        vector<int> pref(N+1, 0);
        map<int, int> m;
        for (int i=0; i<N; i++) {
            pref[i+1] += pref[i] + nums[i];
            m[pref[i+1]%k]++;
        }

        bool ok = false;
        for (int i=0; i<=N; i++) 
            if (m[pref[i]%k] > 1) 
                ok = true;

        return ok;
    }
};