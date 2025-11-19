// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "";
        for (int i=0; i<(int)s.size(); i++) {
            t += '#';
            t += s[i];
        }
        t += '#';

        int N = (int)t.size();
        string ans = "";
        for (int i=0; i<N; i++) {
            int l=i, r=i;
            while (l-1 >= 0 && r+1 < N && t[l-1] == t[r+1]) {
                l--, r++;
            }
            if (r-l+1 > (int)ans.size())
                ans = t.substr(l, r-l+1);
        }
        string ret = "";
        for (char c : ans)
            if (c != '#')
                ret += c;
        return ret;
    }
};