// https://leetcode.com/problems/rotate-array

class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        int N = (int)nums.size();
        const auto sol1 = [&]() {
            vector<int> ans;
            for (int i=(N-k+N)%N; i<N; i++)
                ans.push_back(nums[i]);
            for (int i=0; i<(N-k+N)%N; i++)
                ans.push_back(nums[i]);
            nums = ans;
        };        
        

        sol1();
    }
};