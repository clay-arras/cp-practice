// https://leetcode.com/problems/patching-array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        nums.push_back(n);
        int N = (int)nums.size();
        long long k = nums[0];
        int ans = 0;
        for (int i=1; i<N; i++) {
            while (k+1 < nums[i]) {
                k = 2*k + 1;
                ans++;
            }
            k += nums[i];
        }
        return ans;
    }
};