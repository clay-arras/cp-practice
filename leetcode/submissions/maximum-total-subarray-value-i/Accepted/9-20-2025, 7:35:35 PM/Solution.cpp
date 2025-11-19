// https://leetcode.com/problems/maximum-total-subarray-value-i

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = *max_element(nums.begin(), nums.end());
        long long mn = *min_element(nums.begin(), nums.end());

        return k* 1LL* (mx - mn);
    }
};