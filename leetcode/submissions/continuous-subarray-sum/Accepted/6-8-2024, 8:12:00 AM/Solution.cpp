// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();

        vector<int> pref(N+1, 0);
        for (int i=0; i<N; i++) 
            pref[i+1] += pref[i] + nums[i];

        map<int, int> m;
        for (int i=1; i<N; i++) {
            m[pref[i-1]%k]++;
            if (m[pref[i+1]%k]) 
                return true;
        }

        return false;
    }
};