// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal

class Solution {
public:
    int firstTrue(int l, int r, function<bool(int)> f) {
        r++;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        // binary search + prefix sum + sorting
        // O(NlogN)

        int N = (int)nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pref(N+1, 0);
        for (int i=0; i<N; i++)
            pref[i+1] = pref[i] + nums[i];

        vector<long long> ans;
        for (int j=0; j<(int)queries.size(); j++) {
            auto ok = [&](int k) {
                return nums[k] > queries[j];
            };
            int t = firstTrue(0, N-1, ok);

            long long val = 0;
            val += (pref[N] - pref[t] - queries[j]*1LL*(N - t));
            val += (queries[j]*1LL*t - pref[t]);

            ans.push_back(val);
        }
        return ans;
    }
};