// https://leetcode.com/problems/maximum-score-of-a-good-subarray

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int N = (int)nums.size();
        int mn = nums[k], ans = 0;
        for (int l=k, r=k; l>=0 || r<N; ) {
            if (l-1 < 0 && r+1 >= N) 
                break;
            cout << l << " " << r << endl;
            if (l-1 < 0) {
                // cout << 1 << endl;
                mn = min(mn, nums[++r]);
            } else if (r+1 >= N) {
                // cout << 2 << endl;
                mn = min(mn, nums[--l]);
            } else if (nums[l-1] > nums[r+1]) {
                // cout << 3 << endl;
                mn = min(mn, nums[--l]);
            } else if (nums[l-1] <= nums[r+1]) {
                // cout << 4 << endl;
                mn = min(mn, nums[++r]);
            }
            // cout << mn << endl;
            ans = max(ans, (r - l + 1) * mn);
        }
        return ans;
    }
};