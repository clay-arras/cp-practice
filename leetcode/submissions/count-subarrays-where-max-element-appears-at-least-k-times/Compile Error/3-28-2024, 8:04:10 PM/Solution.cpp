// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long N = (int)nums.size();

        long long maxN = 0;
        for (int i=0; i<N; i++) {
            maxN = max(maxN, nums[i]);
        }

        vector<long long> pref(N+1, 0);
        set<pair<int, int>> s;

        for (int i=1; i<=N; i++) {
            pref[i] = pref[i-1];
            if (nums[i-1] == maxN)
                pref[i] += 1;
            s.insert({pref[i], i-1});
        }

        long long ans = 0;
        for (int i=0; i<N; i++) {
            auto it = s.lower_bound({pref[i] + k, -1});
            if (it != s.end()) {
                ans += N - (*it).second;
                cout << i << " " << (*it).second << endl;
            }
        }
        
        return ans;
    }
};