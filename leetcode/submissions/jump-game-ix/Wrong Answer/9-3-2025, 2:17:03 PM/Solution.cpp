// https://leetcode.com/problems/jump-game-ix

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int N = (int)nums.size();
        vector<pair<int, int>> mx(N), mn(N); // mx: smallest index, mn: biggest index

        pair<int, int> cur = {-1, -1};
        for (int i=0; i<N; i++) {
            cur = max(cur, {nums[i], -i});
            mx[i] = cur;
        }
        cur = {INT_MAX, INT_MAX};
        for (int i=N-1; i>=0; i--) {
            cur = min(cur, {nums[i], -i});
            mn[i] = cur;
        }

        vector<int> ans(N);
        for (int i=0; i<N; i++) {
            int idx = -mn[i].second;
            int val = mn[i].first;

            ans[i] = nums[i];
            if (val < nums[i] && nums[idx] < mx[idx].first) {
                ans[i] = max(ans[i], mx[idx].first);
            }
            if (nums[i] < mx[i].first) {
                ans[i] = max(ans[i], mx[i].first);
            }
        }

        return ans;
    }
    // case: everything to the right of max value is just max value
    // requirement: need a data structure/system that gives the SMALLEST VALUE w/ CERTAIN INDEX to the right
};