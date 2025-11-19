// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    struct _int {
        long long val = -1e9;
    };
    int minSubarray(vector<int>& nums, int p) {
        int N = (int)nums.size();
        long long k = 0;
        for (int i=0; i<N; i++)
            k += nums[i] % p;
        k %= p;

        if (k == 0)
            return 0;

        vector<long long> pref(N+1, 0);
        for (int i=0; i<N; i++)
            pref[i+1] += pref[i] + nums[i];

        unordered_map<int, _int> m;
        long long ans = INT_MAX;
        m[(pref[0] + k)%p].val = 0;
        for (int i=1; i<=N; i++) {
            ans = min(ans, i - m[pref[i]%p].val);
            m[(pref[i] + k)%p].val = i;
        }
        return (ans >= N ? -1 : ans);
    }
};