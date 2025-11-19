// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int N = (int)nums.size();
        long long k = 0;
        for (int i=0; i<N; i++)
            k += nums[i];
        k %= p;

        if (k == 0)
            return 0;

        vector<long long> pref(N+1, 0);
        for (int i=0; i<N; i++)
            pref[i+1] += pref[i] + nums[i];

        map<int, int> m;
        int ans = INT_MAX;
        for (int i=0; i<p; i++)
            m[i] = -(1e9);

        m[(pref[0] + k)%p] = 0;
        for (int i=1; i<=N; i++) {
            // 0 1 3 6
            cout << m[pref[i]%p] << " " << i-1 << endl;
            ans = min(ans, i - m[pref[i]%p]);
            m[(pref[i] + k)%p] = i;
        }
        return (ans >= N ? -1 : ans);
    }
};