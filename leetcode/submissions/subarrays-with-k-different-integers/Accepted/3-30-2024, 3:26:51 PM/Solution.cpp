// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int, int> lm, rm;

        nums.push_back(-1);
        int N = (int)nums.size();
        int i = 0, l = -1, r = -1;

        int lk = k;
        int rk = k;

        int ans = 0;
        for (i=0; i<N; i++) {
            while (rk >= 0) {
                if (r + 1 >= N) break;
                if (rm[nums[r+1]] == 0) rk--;
                r++, rm[nums[r]]++;
            }
            while (lk > 0) {
                if (l + 1 >= N) break;
                if (lm[nums[l+1]] == 0) lk--;
                l++, lm[nums[l]]++;
            }
            lm[nums[i]]--;
            rm[nums[i]]--;
            if (lm[nums[i]] == 0) lk++;
            if (rm[nums[i]] == 0) rk++;
            
            cout << l << " " << r << endl;
            ans += r - l;
        }
        return ans;
    }
};