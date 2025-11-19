// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int N = (int)nums.size();
        int val = 0;
        for (int i=0; i<N; i++) 
            val ^= nums[i];

        vector<int> ans;
        for (int i=0; i<N; i++) {
            if (nums[i] ^ nums[N-i-1] == val || nums[i] ^ nums[N-i-1] == 0)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};