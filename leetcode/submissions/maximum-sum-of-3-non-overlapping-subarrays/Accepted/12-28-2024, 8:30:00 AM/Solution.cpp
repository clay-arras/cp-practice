// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = (int)nums.size();
        vector<int> pref(N-k+1);

        int sum = 0;
        for (int i=0; i<N; i++) {
            sum += nums[i];
            if (i >= k-1) {
                pref[i-k+1] = sum;
                sum -= nums[i-k+1];
            }
        }
        vector<pair<int, int>> lmax(N-k+1);
        lmax[0] = {pref[0], 0};
        for (int i=1; i<N-k+1; i++) 
            lmax[i] = max(lmax[i-1], {pref[i], -i});
        vector<pair<int, int>> rmax(N-k+1);
        rmax[N-k] = {pref[N-k], -(N-k)};
        for (int i=N-k-1; i>=0; i--) 
            rmax[i] = max(rmax[i+1], {pref[i], -i});

        int ans = 0;
        vector<int> ret = {INT_MAX, INT_MAX, INT_MAX};
        for (int i=k; i<=N-2*k; i++) {
            int l = -lmax[i-k].second;
            int r = -rmax[i+k].second;
            if (pref[i] + pref[l] + pref[r] == ans) {
                ret = min(ret, {l, i, r});
            } else if (pref[i] + pref[l] + pref[r] > ans) {
                ans = pref[i] + pref[l] + pref[r];
                ret = {l, i, r};
            }
        }

        return ret;
    }
};