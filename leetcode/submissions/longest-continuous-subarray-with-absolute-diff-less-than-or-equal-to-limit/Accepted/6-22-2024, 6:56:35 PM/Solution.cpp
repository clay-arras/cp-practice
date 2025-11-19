// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int N = (int)nums.size();
        int ans = 1;
        for (int l=0, r=0; r<N; r++) {
            s.insert(nums[r]);
            while (l <= r && !s.empty() && *(s.rbegin()) - *(s.begin()) > limit) {
                s.erase(s.find(nums[l]));
                l++;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};