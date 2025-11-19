// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int firstTrue(int l, int r, function<bool(int)> f) {
        r++;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int lastTrue(int l, int r, function<bool(int)> f) {
        --l;
        for (int diff=r-l; diff>0; diff/=2)
            while (l + diff <= r && f(l + diff))
                l += diff;
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int N = (int)nums.size();    
        if (!N) return {-1, -1};

        int lb = firstTrue(0, N-1, [&](int i) {
            return nums[i] >= target;
        });
        int rb = lastTrue(0, N-1, [&](int i) {
            return nums[i] <= target;
        });
        if (lb < 0 || lb >= N || nums[lb] != target)
            return {-1, -1};
        if (rb < 0 || rb >= N || nums[rb] != target)
            return {-1, -1};
        return {lb, rb};
    }
};