// https://leetcode.com/problems/split-array-with-minimum-difference

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int N = (int)nums.size();
        if (N == 2)
            return abs(nums[0] - nums[1]);

        long long l=0, lsum = 0;
        for (; l<N-1; l++) {
            if (nums[l] >= nums[l+1])
                break;
            lsum += nums[l];
        }

        long long r=N-1, rsum = 0;
        for (; r>=1; r--) {
            if (nums[r-1] <= nums[r])
                break;
            rsum += nums[r];
        }
        if (l != r) return -1;
        
        return min(abs((lsum - (rsum - nums[l]))), 
                   abs(((lsum - nums[l]) - rsum)));
    }
};