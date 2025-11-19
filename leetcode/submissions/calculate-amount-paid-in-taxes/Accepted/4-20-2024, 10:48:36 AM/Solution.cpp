// https://leetcode.com/problems/calculate-amount-paid-in-taxes

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int N = (int)brackets.size();
        double ans = 0;
        ans += brackets[0][1] * 0.01 * min(income, brackets[0][0]);   
        for (int i=1; i<N; i++) {
            ans += brackets[i][1] * 0.01 * max(0, min(income, brackets[i][0]) - brackets[i-1][0]);   
        }
        return ans;
    }
};