// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int N = (int)nums.size();
        deque<int> mn, mx;
        
        int ans = 0;
        for (int l=0, r=0; l<N && r<N; r++) {
            while (!mx.empty() && mx.back() < nums[r]) 
                mx.pop_back();
            mx.push_back(nums[r]);
            while (!mn.empty() && mn.back() > nums[r]) 
                mn.pop_back();
            mn.push_back(nums[r]);
            
            while (mx.front() - mn.front() > limit) {
                if (mx.front() == nums[l])
                    mx.pop_front();
                if (mn.front() == nums[l])
                    mn.pop_front();
                l++;
            }
            
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};