// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int N = (int)nums.size();
        nums.push_back(0);

        int l=0, r;
        for (r=0; r<N && k>0; r++) {
            if (nums[r+1] == 0) k--;
        }
        int ans = r - l + 1;
        while (r<N) {
            r++;
            while(nums[r+1] == 1) r++;
            while(nums[l] == 1) l++;
            l++;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};