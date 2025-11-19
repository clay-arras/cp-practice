// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string best = "";
        int l1 = (int)str1.size(), l2 = (int)str2.size();
        if (l1 > l2) swap(str1, str2);
        for (int i=1; i<=min(l1, l2); i++) {
            if (l1 % i == 0 and l2 % i == 0) {
                string subst = str1.substr(0, i);
                string res = "";
                for (int j=0; j<=l2/i; j++) {
                    res += subst;
                }
                if (res == str2) best = subst;
            }
        }
        return best;
    }
};