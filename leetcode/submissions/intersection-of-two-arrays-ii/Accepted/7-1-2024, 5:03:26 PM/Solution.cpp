// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1, m2;
        for (int i : nums1)
            m1[i]++;
        for (int i : nums2)
            m2[i]++;
        
        vector<int> ans;
        for (auto [k, v] : m1) {
            int x = min(v, m2[k]);
            for (int i=0; i<x; i++)
                ans.push_back(k);
        }
        return ans;

    }
};