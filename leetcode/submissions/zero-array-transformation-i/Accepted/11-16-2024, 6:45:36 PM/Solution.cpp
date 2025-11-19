// https://leetcode.com/problems/zero-array-transformation-i

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N = (int)nums.size();
        vector<int> diff(N+1, 0);
        for (auto q : queries) {
            diff[q[0]]--;
            diff[q[1]+1]++;
        }
        vector<int> A(N, 0);

        A[0] = diff[0];
        for (int i=1; i<N; i++)
            A[i] = diff[i] + A[i-1];

        bool ans = true;
        for (int i=0; i<N; i++)
            ans &= ((A[i] + nums[i]) <= 0);
        return ans;
    }
};