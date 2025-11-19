// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int N = (int)nums.size();
        int a = 0, b = 0;
        vector<int> ans;
        for (int i=0; i<N; i++) {
            a ^= nums[i];
            b ^= nums[N-i-1];
            if (a ^ b == val || a ^ b == 0)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};