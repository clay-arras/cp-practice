// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int N = (int)nums.size();
        vector<int> diff(N+1, 0);

        int ans = 0;
        bool ok = true;
        for (int i=0; i<N; i++) {
            if (i) diff[i] += diff[i-1];
            if (i+k <= N && (diff[i] + nums[i]) % 2 == 0) {
                diff[i]++;
                diff[i+k]--;
                ans++;
            }
            if (i+k > N) ok &= (diff[i] + nums[i]) % 2;
        }
        return (ok ? ans : -1);
    }
};