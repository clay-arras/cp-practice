// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string best = "";
        int l1 = (int)str1.size(), l2 = (int)str2.size();
        if (l1 > l2) swap(str1, str2);
        for (int i=1; i<=min(l1, l2); i++) {
            string subst = str1.substr(0, i);
            cout << subst << " ";
            if (isMadeOf(subst, str1) and isMadeOf(subst, str2)) {
                best = subst;
                cout << best << " ";
            }
            cout << endl;
        }
        return best;
    }
    bool isMadeOf(string subst, string s) {
        int len = (int)s.size();
        cout << ";" << len << " " << s << endl;
        if (len % (int)subst.size() == 0) {
            string res = "";
            while ((int)res.size() < (int)s.size()) {
                res += subst;
            }
            cout << "." << res << " " << s << endl;
            return (res == s);
        }
        return false;
    }
};