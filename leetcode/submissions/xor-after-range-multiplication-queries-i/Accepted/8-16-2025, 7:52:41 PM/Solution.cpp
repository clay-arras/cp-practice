// https://leetcode.com/problems/xor-after-range-multiplication-queries-i

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> num;
        for (int i : nums)
            num.push_back(1LL * i);
        
        const int MOD = 1e9+7;
        for (auto q : queries) {
            int l=q[0], r=q[1], k=q[2], v=q[3];
            for (int i=l; i<=r; i+=k) {
                num[i] = (num[i] * 1LL * v) % MOD;
            }
        }
        int xo = num[0];
        for (int i=1; i<(int)num.size(); i++)
            xo ^= num[i];
        return xo;
    }
};