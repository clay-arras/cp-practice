// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int N = (int)nums.size();
        priority_queue<pair<int, int>> mx;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn;
        
        int ans = 0;
        for (int l=0, r=0; l<N; l++) {
            int mxv = (mx.empty() ? 0 : mx.top().first);
            int mnv = (mn.empty() ? INT_MAX : mn.top().first);
            while (r < N && max(nums[r], mxv) - min(nums[r], mnv) <= limit) {
                mx.push({nums[r], r});
                mn.push({nums[r], r});
                r++;
            }
            while (!mx.empty() && mx.top().second <= r)
                mx.pop();
            while (!mn.empty() && mn.top().second <= r)
                mn.pop();
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};