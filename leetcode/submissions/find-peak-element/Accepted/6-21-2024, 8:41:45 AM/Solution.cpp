// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int lastTrue(int l, int r, function<bool(int)> f) {
        l--;
        for (int diff=r-l; diff>0; diff/=2)
            while (l + diff <= r && f(l + diff))
                l += diff;
        return l;
    }

    int findPeakElement(vector<int>& nums) {
        int N = (int)nums.size();
        return lastTrue(1, N-1, [&](int k) {
            return nums[k] > nums[k-1];
        });
    }
};