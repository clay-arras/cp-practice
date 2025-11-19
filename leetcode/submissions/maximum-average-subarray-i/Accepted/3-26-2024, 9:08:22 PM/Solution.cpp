// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = 0;
        int N = (int)nums.size();
        for (int i=0; i<k; i++) {
            ans += nums[i];
        }
        int count = ans;
        for (int i=k; i<N; i++) {
            count -= nums[i-k];
            count += nums[i];
            ans = max(ans, count);
        }

        return ans*1.0 / k;
    }
};