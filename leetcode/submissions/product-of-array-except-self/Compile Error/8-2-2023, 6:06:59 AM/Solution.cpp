// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long mult = 1;
        for (auto i : nums)
            mult *= 1LL * nums;
            
        vector<int> ans;
        for (auto i : nums)
            ans.push_back(mult / i);
        
        return ans;
    }
};