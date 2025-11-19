// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int N = (int)nums.size();
        int val = 0;
        for (auto i : nums)
            val ^= i;
        
        int a=0, b=0;
        for (int i=0; i<32; i++) {
            if (val & (1 << i)) {
                for (auto j : nums) {
                    if (j & (1 << i)) {
                        a ^= j;
                    } else {
                        b ^= j;
                    }
                }
                return {a, b}; 
            }
        }
        return {};
    }
};