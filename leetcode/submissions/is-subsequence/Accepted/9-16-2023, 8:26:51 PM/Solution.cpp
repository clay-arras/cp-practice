// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        s.push_back(' ');
        t.push_back(' ');
        int sl = (int)s.size(), tl = (int)t.size();
        int sp, tp;
        for (sp=0, tp=0; sp<sl and tp<tl; sp++, tp++) {
            while (s[sp] != t[tp]) {
                tp++;
                if (tp == tl)
                    return false;
            }
        }
        return (s[sp] == t[tp]);
    }
};