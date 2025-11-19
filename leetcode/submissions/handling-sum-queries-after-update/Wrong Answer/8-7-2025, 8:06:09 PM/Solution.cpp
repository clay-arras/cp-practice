// https://leetcode.com/problems/handling-sum-queries-after-update

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int N = (int)nums1.size();
        
        vector<int> pref(N+1);
        int roll = 0;
        for (int i=0; i<N; i++) {
            roll += (nums1[i] ? -1 : 1);
            pref[i+1] = roll;
        }
        
        long long sum = 0; 
        long long push = 0;
        for (int i=0; i<N; i++) {
            sum += nums2[i];
            push += nums1[i];
        }
        
        vector<long long> ans;
        for (auto q : queries) {
            if (q[0] == 1) {
                push += - pref[q[1]] + pref[q[2]+1];
            } else if (q[0] == 2) {
                sum += q[1] * push;
            } else if (q[0] == 3) {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};