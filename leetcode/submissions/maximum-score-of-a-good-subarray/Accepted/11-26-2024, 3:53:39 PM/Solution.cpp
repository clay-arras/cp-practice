// https://leetcode.com/problems/maximum-score-of-a-good-subarray

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int N = (int)nums.size();
        int mn = nums[k], ans = nums[k];
        for (int l=k, r=k; l-1>=0 || r+1<N; ) {
            if (l-1 < 0) 
                mn = min(mn, nums[++r]);
            else if (r+1 >= N)
                mn = min(mn, nums[--l]);
            else if (nums[l-1] > nums[r+1])
                mn = min(mn, nums[--l]);
            else if (nums[l-1] <= nums[r+1])
                mn = min(mn, nums[++r]);
                
            ans = max(ans, (r - l + 1) * mn);
        }
        return ans;
    }
};