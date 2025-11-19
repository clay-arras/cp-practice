// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // step 1: prefix sum over the fruits O(N)
        // total: O(N+K)

        int N = (int)fruits.size();
        int lbnd = min(startPos, fruits[0][0]);
        int rbnd = max(startPos, fruits[N-1][0])+k+1;

        vector<int> arr(rbnd, 0);
        for (int i=0; i<N; i++)
            arr[fruits[i][0]] += fruits[i][1];
        vector<int> pref(rbnd+1, 0);
        for (int i=1; i<=rbnd; i++) 
            pref[i] = pref[i-1] + arr[i-1];
        
        int ans = 0;
        for (int i=0; i<k; i++) {
            int l = i;
            int r = max((k - 2*i), 0);
            ans = max(ans, pref[startPos + r + 1] - pref[startPos - l]);
        }
        for (int i=0; i<k; i++) {
            int l = max((k - 2*i), 0);
            int r = i;
            ans = max(ans, pref[startPos + r + 1] - pref[startPos - l]);
        }
        return ans;
    }
};