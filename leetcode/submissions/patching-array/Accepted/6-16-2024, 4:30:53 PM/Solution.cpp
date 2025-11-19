// https://leetcode.com/problems/patching-array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        nums.push_back(INT_MAX);
        int N = (int)nums.size();
        long long k = 0;
        int ans = 0;
        for (int i=0; i<N; i++) {
            while (k+1 < nums[i]) {
                if (k < n) ans++;
                k = 2*k + 1;
            }
            k += nums[i];
        }
        return ans;
    }
};