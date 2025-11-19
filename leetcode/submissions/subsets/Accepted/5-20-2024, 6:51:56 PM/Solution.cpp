// https://leetcode.com/problems/subsets

class Solution {
public:
    int N;
    vector<vector<int>> ans;
    vector<int> sub;
    void solve(int i, vector<int>& nums) {
        if (i == N) {
            ans.push_back(sub);
        } else {
            solve(i+1, nums);
            sub.push_back(nums[i]);
            solve(i+1, nums);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        N = (int)nums.size();
        solve(0, nums);
        return ans;
    }
};