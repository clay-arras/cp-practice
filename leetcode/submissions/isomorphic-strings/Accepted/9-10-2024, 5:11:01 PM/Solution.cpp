// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int N = (int)s.size();
        map<int, int> st, ts;
        bool ok = true;
        for (int i=0; i<N; i++) {
            if (st.contains(s[i]) && st[s[i]] != t[i])
                ok = false;
            if (ts.contains(t[i]) && ts[t[i]] != s[i])
                ok = false;
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        return ok;
    }
};