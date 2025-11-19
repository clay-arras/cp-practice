// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();
        int ans = 0, sum = 0, ok = 0;
        map<int, int> cnt;
        for (int i=0; i<N; i++) {
            if (i >= k) {
                sum -= nums[i-k];
                cnt[nums[i-k]]--;
                if (cnt[nums[i-k]] == 1) 
                    ok--;
            }
            sum += nums[i];
            if (cnt[nums[i]] == 1) 
                ok++;
            cnt[nums[i]]++;

            if (!ok && i+1 >= k) ans = max(ans, sum);
        }
        return ans;
    }
};