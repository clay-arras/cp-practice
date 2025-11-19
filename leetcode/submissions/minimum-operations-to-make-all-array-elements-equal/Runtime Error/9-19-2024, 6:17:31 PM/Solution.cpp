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
        vector<int> pref(N+1, 0);
        for (int i=0; i<N; i++)
            pref[i+1] = pref[i] + nums[i];
        
        for (int i : nums)
            cout << i << " ";
        cout << endl;
        for (int i : pref)
            cout << i << " ";
        cout << endl;

        vector<long long> ans;
        for (int j=0; j<(int)queries.size(); j++) {
            auto ok = [&](int k) {
                return nums[k] > queries[j];
            };
            for (int i=0; i<N; i++)
                cout << ok(i) << " ";
            cout << endl;
            int t = firstTrue(0, N-1, ok);
            cout << t << endl;

            int val = 0;
            val += (pref[N] - pref[t] - queries[j]*(N - t));
            val += (queries[j]*t - pref[t]);

            ans.push_back(val);
        }
        return ans;
    }
};