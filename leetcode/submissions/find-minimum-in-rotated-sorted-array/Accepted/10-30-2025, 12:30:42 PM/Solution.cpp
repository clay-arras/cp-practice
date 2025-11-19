// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

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

    int findMin(vector<int>& nums) {
        int N = (int)nums.size(); 
        int idx = firstTrue(1, N-1, [&](int i) {
            return nums[i] < nums[0];
        });
        if (idx == N) 
            return nums[0];
        return nums[idx];
    }
};