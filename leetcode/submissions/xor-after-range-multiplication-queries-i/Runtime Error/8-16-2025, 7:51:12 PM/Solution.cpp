// https://leetcode.com/problems/xor-after-range-multiplication-queries-i

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        for (auto q : queries) {
            int l=q[0], r=q[1], k=q[2], v=q[3];
            for (int i=l; i<=r; i+=k) {
                nums[i] = (nums[i] * v) % MOD;
            }
        }
        int xo = nums[0];
        for (int i=1; i<(int)nums.size(); i++)
            xo ^= nums[i];
        return xo;
    }
};