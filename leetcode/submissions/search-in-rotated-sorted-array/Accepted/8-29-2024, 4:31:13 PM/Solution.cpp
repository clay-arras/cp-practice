// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int lastTrue(int l, int r, function<bool(int)> f) {
        l--;
        for (int diff=r-l; diff>0; diff/=2) 
            while (l + diff <= r && f(l + diff))
                l += diff;
        return l;
    }

    int search(vector<int>& nums, int target) {
        int N = (int)nums.size();
        int p = lastTrue(0, N-1, [&](int i) {
            return nums[i] >= nums[0];
        });
        
        int l = lastTrue(0, p, [&](int i) {
            return nums[i] <= target;
        });
        int r = lastTrue(p + 1, N-1, [&](int i) {
            return nums[i] <= target;
        });

        if (l >= 0 && nums[l] == target)
            return l;
        if (nums[r] == target)
            return r;
        return -1;
    }
};



