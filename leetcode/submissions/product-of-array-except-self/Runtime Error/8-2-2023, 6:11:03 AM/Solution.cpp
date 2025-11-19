// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long mult = 1, nonz = 1;
        int N = (int)nums.size();
        int cnt = 0;
        for (int i=0; i<N; i++) {
            mult *= nums[i];
            nonz *= (nums[i] ? nums[i] : 1);
            if (!nums[i]) cnt++;
        }
            
        vector<int> ans;
        for (auto i : nums) {
            if (cnt == 1 and i == 0) {
                ans.push_back(nonz);
            } else {
                ans.push_back(mult / i);
            }
        }
        
        return ans;
    }
};