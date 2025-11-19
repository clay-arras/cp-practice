// https://leetcode.com/problems/smallest-missing-multiple-of-k

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i : nums) 
            m[i]++;
        
        for (int i=1; i<=101; i++) {
            if (m[i*k] == 0)
                return i*k;
        }

        return INT_MAX; 
    }
};