// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ans = true;

        // sort(bills.begin(), bills.end());
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
            if (m[5] >= 3) {
                m[5] -= 2;
                m[10] += 1;
            }
        }

        return ans;
    }
};

// 5 : 9
// 10: 0
// 20: 1