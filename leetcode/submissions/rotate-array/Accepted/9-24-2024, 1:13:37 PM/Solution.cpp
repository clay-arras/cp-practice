// https://leetcode.com/problems/rotate-array

class Solution {
public:

    const static long long MX = 1e6+1;
    void rotate(vector<int>& nums, int k) {
        int N = (int)nums.size();
        const auto sol1 = [&]() {
            vector<int> ans;
            for (int i=(MX*N-k)%N; i<N; i++)
                ans.push_back(nums[i]);
            for (int i=0; i<(MX*N-k)%N; i++)
                ans.push_back(nums[i]);
            nums = ans;
        };        
        

        sol1();
    }
};