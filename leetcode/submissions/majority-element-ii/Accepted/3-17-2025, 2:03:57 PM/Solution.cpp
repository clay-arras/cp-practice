// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;

        vector<int> ans;
        for (auto [k, v] : m)
            if (v > (int)nums.size()/3)
                ans.push_back(k);
        return ans;
    }
};