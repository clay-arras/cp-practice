// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto i : nums)
            m[i]++;

        int ans = 0;
        for (int i=0; i<(int)nums.size(); i++) {
            ans += m[k - nums[i]];
        }
        return ans;
    }
};