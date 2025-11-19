// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N = (int)nums.size();

        bool ok = false;
        vector<int> pref(N+1, 0);
        for (int i=0; i<N; i++) {
            pref[i+1] += pref[i] + nums[i];
            // if (i > 1) ok |= !(pref[i+1] % k);
        }

        map<int, int> m;
        for (int i=1; i<N; i++) {
            m[pref[i-1]%k]++;
            if (m[pref[i+1]%k]) {
                cout << i << endl;
                ok = true;
            }
        }

        for (auto [k, v] : m)
            cout << k << " " << v << endl;
        for (auto i : pref)
            cout << i << " ";

        return ok;
    }
};