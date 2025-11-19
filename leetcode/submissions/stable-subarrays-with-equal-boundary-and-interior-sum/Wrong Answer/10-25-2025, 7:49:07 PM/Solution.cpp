// https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum

class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int N = (int)capacity.size();
        vector<long long> pref(N+1, 0);
        for (int i=1; i<=N; i++)
            pref[i] = pref[i-1] + capacity[i-1];    

        long long ans = 0;
        unordered_map<int, unordered_map<long long, int>> m;
        for (int i=0; i<N; i++) {
            ans += m[capacity[i]][pref[i+1] - capacity[i]];
            m[capacity[i]][pref[i+1]]++;
        }

        return ans;
    }
};