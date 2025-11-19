// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii

class Solution {
public:
    struct Orray {
        vector<int> cnt;
        Orray() : cnt(31, 0) {}
        int sum() {
            int s = 0;
            for (int i=0; i<31; i++) {
                if (cnt[i]) s += (1 << i);
            }
            return s;
        }
        void operator+=(int const& i) {
            for (int j=31; j>=0; j--) 
                if (i & (1 << j))
                    cnt[j]++;
        }
        void operator-=(int const& i) {
            for (int j=31; j>=0; j--) 
                if (i & (1 << j))
                    cnt[j]--;
        }
    };

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int N = (int)nums.size();
        int ans = INT_MAX;

        Orray arr;
        for (int l=0, r=-1; l<N && r<N; l++) {
            while (r+1<N && (arr.sum() < k || l>r)) {
                r++;
                arr += (nums[r]);
            }
            if (arr.sum() >= k)
                ans = min(ans, r-l+1);
            arr -= (nums[l]); 
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};