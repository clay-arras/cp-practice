// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int, int> sm, tm;

        int N = (int)s.size();
        bool ans = true;
        for (int i=0; i<N; i++) {
            if (sm[s[i]-'a'+1] == 0)
                sm[s[i]-'a'+1] = t[i]-'a'+1;
            ans &= (sm[s[i]-'a'+1] == t[i]-'a'+1);
            // if (tm[t[i]-'a'] == 0)
            //     tm[t[i]-'a'] = s[i]-'a';
            // ans &= (tm[t[i]-'a'] == s[i]-'a');
        }
        return ans;
    }
};