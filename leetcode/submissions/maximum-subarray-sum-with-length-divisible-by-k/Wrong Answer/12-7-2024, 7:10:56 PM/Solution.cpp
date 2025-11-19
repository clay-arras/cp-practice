// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k

class Solution {
public:
    int firstTrue(int l, int r, function<bool(int)> f) {
        r++;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    long long maximumSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();
        long long ans = LLONG_MIN, sum = 0, ok = 0;
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

    long long maxSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();
        const auto ok = [&](int p) {
            if (p == N/k) 
                return true;
            return maximumSubarraySum(nums, p*k) > maximumSubarraySum(nums, (p+1)*k);
        };
        long long ans = firstTrue(1, N/k, ok);
        return maximumSubarraySum(nums, ans * k);
    }
};