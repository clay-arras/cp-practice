// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int N = (int)nums.size();
        for (int i=0; i<N; i++) {
            m[nums[i]] = i;
        }

        sort(nums.begin(), nums.end());
        int i = 0, j = (int)nums.size() - 1;

        while (i != j) {
            if (nums[i] + nums[j] > target) {
                j--;
            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                return {m[nums[i]], m[nums[j]]};
            }
        }
        return {-1, -1};
    }
};