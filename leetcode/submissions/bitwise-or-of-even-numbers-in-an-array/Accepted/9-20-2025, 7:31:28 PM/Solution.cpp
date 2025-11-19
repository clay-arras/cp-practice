// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;   
        int N = (int)nums.size();
        for (int i=0; i<N; i++) {
            if (nums[i] % 2 == 0) 
                ans |= nums[i];
        }
        return ans;
    }
};