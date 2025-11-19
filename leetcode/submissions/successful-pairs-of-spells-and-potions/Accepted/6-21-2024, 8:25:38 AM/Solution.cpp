// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

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

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int N = (int)spells.size(), M = (int)potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(N, 0);
        for (int i=0; i<N; i++) {
            int val = M - firstTrue(0, M-1, [&](int k){
                return spells[i] * 1LL * potions[k] >= success;
            });
            ans[i] = val;
        }

        return ans;
    }
};