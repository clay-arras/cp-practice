// https://leetcode.com/problems/maximum-product-of-three-elements-after-one-replacement

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int N = (int)nums.size();
        for (int i=0; i<N; i++)
            nums[i] = abs(nums[i]);
        sort(nums.rbegin(), nums.rend());

        return abs(1e5 *1LL* nums[0] * nums[1]);
    }
};