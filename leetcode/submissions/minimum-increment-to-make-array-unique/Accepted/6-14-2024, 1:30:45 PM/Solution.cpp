// https://leetcode.com/problems/minimum-increment-to-make-array-unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int N = (int)nums.size();
        int ans = 0;

        sort(nums.begin(), nums.end());
        for (int i=1; i<N; i++) {
            int val = max(0, nums[i-1] - nums[i] + 1);
            ans += val;
            nums[i] += val;
        }

        return ans;
    }
};