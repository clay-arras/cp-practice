// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    const static int OFFSET = 1e4+1;
    const static int MXN = 1e4+1 + OFFSET;
    int findKthLargest(vector<int>& nums, int k) {
        int N = (int)nums.size();
        int mxV = -MXN;
        vector<int> cnt(MXN, 0);
        for (int i=0; i<N; i++) {
            nums[i] += OFFSET;
            cnt[nums[i]]++;
            mxV = max(mxV, nums[i]);
        }

        int count = 0;
        for (int i=mxV; i>=0; i--) {
            count += cnt[i];
            if (count >= k) 
                return i - OFFSET;
        }
        return -1;
    }
};