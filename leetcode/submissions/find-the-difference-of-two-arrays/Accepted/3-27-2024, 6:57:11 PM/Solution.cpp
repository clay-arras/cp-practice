// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1, m2;
        for (auto i : nums1)
            m1[i]++;
        for (auto i : nums2)
            m2[i]++;

        vector<vector<int>> ans(2, vector<int>());
        for (auto i : nums1){
            if (m2[i] == 0) {
                ans[0].push_back(i);
                m2[i]++;
            }
        }
        for (auto i : nums2){
            if (m1[i] == 0) {
                ans[1].push_back(i);
                m1[i]++;
            }
        }
        return ans;
    }
};