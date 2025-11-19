// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int N = (int)nums.size();
        for (int i=0; i<N; i++) {
            for (int l=0, r=N-1; l<i && r>i; ) {
                if (nums[l] + nums[r] > -nums[i]) r--;
                else if (nums[l] + nums[r] < -nums[i]) l++;
                else {
                    ans.push_back({nums[l], nums[i], nums[r]});
                    l++, r--;
                }
            }
        }

        return ans;
    }
};