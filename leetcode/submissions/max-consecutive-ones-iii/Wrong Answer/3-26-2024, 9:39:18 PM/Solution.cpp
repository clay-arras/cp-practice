// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int N = (int)nums.size();

        int l=0, r=-1;
        int kCount = k;
        while (kCount>0 && r<N-1) {
            r++;
            if (nums[r] == 0) 
                kCount--;
        }

        int ans = r - l + 1;
        for (; l<N && r<N;) {
            while (l <= r && nums[l] == 1) 
                l++;
            r++, l++;
            while (r+1 < N && nums[r+1] == 1)
                r++;
            ans = max(ans, r-l + 1);
        }    
        return ans;
    }
};