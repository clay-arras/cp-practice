// https://leetcode.com/problems/count-number-of-nice-subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int N = (int)nums.size();

        auto atMost = [&](int k){
            int cnt = 0;
            for (int l=0, r=0; r<N; r++) {
                k -= nums[r] % 2;
                while (l <= r && k < 0) {
                    k += (nums[l] % 2);
                    l++;
                }
                cnt += r - l + 1;
            }
            return cnt;
        };

        return atMost(k) - atMost(k-1);
    }
};