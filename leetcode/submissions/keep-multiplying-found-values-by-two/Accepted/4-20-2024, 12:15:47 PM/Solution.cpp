// https://leetcode.com/problems/keep-multiplying-found-values-by-two

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int, int> m;
        for (auto i : nums)
            m[i]++;

        while (m[original] != 0) {
            original *= 2;
        }
        return original;
    }
};