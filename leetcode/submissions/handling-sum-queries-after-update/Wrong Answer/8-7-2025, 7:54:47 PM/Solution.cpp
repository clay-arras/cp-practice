// https://leetcode.com/problems/handling-sum-queries-after-update

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int N = (int)nums1.size();
        
        long long sum = 0; 
        for (int i=0; i<N; i++)
            sum += nums1[i] * nums2[i];
        
        vector<int> pref(N);
        int roll = 0;
        for (int i=0; i<N; i++) {
            roll += (nums1[i] ? -1 : 1) * nums2[i];
            pref[i] = roll;
        }
        
        long long push = 0;
        vector<long long> ans;
        for (auto q : queries) {
            if (q[0] == 1) {
                // sum += pref[q[1]] + pref[q[2]];
            } else if (q[0] == 2) {
                // push += 
            } else if (q[0] == 3) {

            }
        }
        return ans;
    }
};