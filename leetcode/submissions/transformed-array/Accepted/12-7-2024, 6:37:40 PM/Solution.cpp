// https://leetcode.com/problems/transformed-array

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int N = (int)nums.size();
        vector<int> res(N);
        for (int i=0; i<N; i++) 
            res[i] = nums[(i + nums[i] + 100*N) % N];
        
        return res;
    }
};