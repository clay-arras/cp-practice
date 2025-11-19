// https://leetcode.com/problems/find-missing-elements

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        
        unordered_map<int, int> m;
        for (int i : nums) 
            m[i]++;
        vector<int> ans;

        for (int i=mn; i<=mx; i++) {
            if (m[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};