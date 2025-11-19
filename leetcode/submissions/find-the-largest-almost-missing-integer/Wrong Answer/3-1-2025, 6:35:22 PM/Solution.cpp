// https://leetcode.com/problems/find-the-largest-almost-missing-integer

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int N = (int)nums.size();
        unordered_map<int, int> m;
        for (int i=1; i<N-1; i++) {
            m[nums[i]]++; 
        }

        int s = (m[nums[0]] ? -1 : nums[0]);
        int e = (m[nums[N-1]] ? -1 : nums[N-1]);
        return (s == e ? -1 : max(s, e));
    }
};