// https://leetcode.com/problems/maximum-subarray-with-equal-products

// #include <boost/math/common_factor.hpp>

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;    

        int N = (int)nums.size();
        for (int l=0; l<N; l++) {
            for (int r=l; r<N; r++) {
                long long prod = nums[l];
                long long gcd_ = nums[l];
                long long lcm_ = nums[l];
                for (int i=l+1; i<=r; i++) {
                    if (prod >= 1e16)
                        break;
                    prod *= nums[i];
                    gcd_ = gcd(gcd_, nums[i]);
                    lcm_ = lcm(lcm_, nums[i]);
                }
                if (prod == gcd_ * lcm_)
                    ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};