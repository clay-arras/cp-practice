// https://leetcode.com/problems/patching-array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // nums.push_back(n);
        int N = (int)nums.size();
        long long k = 0;
        int ans = 0;
        for (int i=0; k<n; i++) {
            while (k+1 < (i >= N ? n : nums[i])) {
                k = 2*k + 1;
                ans++;
            }
            if (i < N)
                k += nums[i];
        }
        return ans;
    }
};