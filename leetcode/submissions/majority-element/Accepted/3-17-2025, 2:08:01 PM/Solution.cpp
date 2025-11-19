// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;

        for (auto [k, v] : m)
            if (v > (int)nums.size() / 2)
                return k;
        return -1;
    }
};