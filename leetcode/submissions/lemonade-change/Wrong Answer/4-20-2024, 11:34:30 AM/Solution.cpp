// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ans = true;

        map<int, int> m;
        for (auto i : bills) {
            m[i]++;
            if (i == 10) {
                m[5]--;
                ans &= (m[5] >= 0);
            }
            if (i == 20) {
                m[5]--;
                m[10]--;
                ans &= (m[5] >= 0);
                ans &= (m[10] >= 0);
            }
        }

        return ans;
    }
};