// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> cnt(31, 0);
        const auto add = [&](int i) {
            for (int j=31; j>=0; j--) 
                if (i & (1 << j))
                    cnt[j]++;
        };
        const auto sub = [&](int i) {
            for (int j=31; j>=0; j--) 
                if (i & (1 << j))
                    cnt[j]--;
        };
        const auto sum = [&]() {
            int s = 0;
            for (int i=0; i<31; i++) {
                if (cnt[i]) s += (1 << i);
            }
            return s;
        };

        int N = (int)nums.size();
        int ans = INT_MAX;
        for (int l=0, r=-1; l<N && r<N; l++) {
            while (r+1<N && (sum() < k || l > r)) {
                r++;
                add(nums[r]);
            }
            if (sum() >= k)
                ans = min(ans, r-l+1);
            sub(nums[l]); 
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};