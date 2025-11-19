// https://leetcode.com/problems/maximum-balanced-shipments

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int N = (int)weight.size();
        int ans = 0;
        for (int i=1; i<N; i++) {
            if (weight[i] < weight[i-1]) {
                ans++, i++;
            }
        }
        return ans;
    }
};