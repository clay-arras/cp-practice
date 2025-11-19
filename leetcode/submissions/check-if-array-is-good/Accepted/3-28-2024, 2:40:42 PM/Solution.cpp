// https://leetcode.com/problems/check-if-array-is-good

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N=(int)nums.size();
        for (int i=0; i<N-1; i++) {
            if (nums[i] != i+1) {
                return false;
            }
        }
        if (nums[N-1] != N - 1)
            return false;
        return true;
    }
};