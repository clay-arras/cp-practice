// https://leetcode.com/problems/split-array-with-minimum-difference

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int N = (int)nums.size();

        int l=0, lsum = 0;
        for (; l<N-1; l++) {
            lsum += nums[l];
            if (nums[l] >= nums[l+1])
                break;
        }

        int r=N-1, rsum = 0;
        for (; r>=1; r--) {
            rsum += nums[r];
            if (nums[r-1] <= nums[r])
                break;
        }
        if (l != r) return -1;
        return min(abs((lsum - (rsum - nums[l]))), 
                   abs(((lsum - nums[l]) - rsum)));
    }
};