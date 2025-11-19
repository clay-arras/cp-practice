// https://leetcode.com/problems/check-if-array-is-good

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=1, N=(int)nums.size(); i<=N; i++) {
            if (i == N && nums[i] != N-1) {
                return false;
            }
            if (nums[i] != i) {
                return false;
            }
        }
        return true;
    }
};