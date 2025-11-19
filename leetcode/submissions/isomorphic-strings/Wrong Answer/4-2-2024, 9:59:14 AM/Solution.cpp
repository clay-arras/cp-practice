// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> sm, tm;

        int N = (int)s.size();
        bool ans = true;
        for (int i=0; i<N; i++) {
            ans &= ++sm[s[i]] == ++ tm[t[i]];
        }
        return ans;
    }
};