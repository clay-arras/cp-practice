// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int N = (int)nums.size();
        vector<int> pref(N+1);

        for (int i=0; i<N; i++) {
            pref[i+1] = pref[i] + nums[i];
        }
        for (int i=0; i<N; i++) {
            if (pref[i] == pref[N] - pref[i + 1]) {
                return i;
            }
        }

        return -1;
    }
};