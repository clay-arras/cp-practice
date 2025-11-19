// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> m; 
        int N = (int)nums.size();
        int ans = 0;
        for (int l=0, r=0, last=-1; r<N; r++) {
            m[nums[r]]++;
            if (m[nums[r]] > k)
                last = nums[r];
            while (m[last] > k) {
                m[nums[l]]--;
                l++;
            }
            ans = max(ans, r-l);
        }
        return ans + 1;
    }
};