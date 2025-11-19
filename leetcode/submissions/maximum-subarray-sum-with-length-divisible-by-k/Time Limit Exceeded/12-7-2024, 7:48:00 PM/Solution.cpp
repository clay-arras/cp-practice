// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();
        long long ans = LLONG_MIN, sum = 0, ok = 0;
        map<int, int> cnt;
        for (int i=0; i<N; i++) {
            if (i >= k)
                sum -= nums[i-k];
            sum += nums[i];
            cnt[nums[i]]++;
            if (i+1 >= k) ans = max(ans, sum);
        }
        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();
        // long long curr = nums[0];
        // long long ans = -1e14;
        // vector<int> idx;
        // idx.push_back(0);

        // for (int i=1; i<N; i++) {
        //     if (curr < 0) {
        //         idx.clear();
        //         idx.push_back(i);
        //         curr = nums[i];
        //     } else if (curr == 0) {
        //         idx.push_back(i);
        //         curr = nums[i];
        //     } else {
        //         curr += nums[i];
        //     }
            
        //     bool ok = false;
        //     for (int j : idx) {
        //         ok |= !((i - j + 1) % k);
        //     }
        //     if (ok) {
        //         ans = max(ans, curr);
        //     }
        // }

        // return max(ans, maximumSubarraySum(nums, k));
        long long ans = -1e14;
        for (int i=k; i<=N; i+=k) {
            ans = max(ans, maximumSubarraySum(nums, i));
        }
        return ans;
    }
};