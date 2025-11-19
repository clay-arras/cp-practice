// https://leetcode.com/problems/compute-decimal-representation

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        for (int i=0; n > 0; i++) {
            if (n % 10)
                ans.push_back(pow(10, i) * (n % 10));
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};