// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) 
            t += string(1, c) + "#";

        int N = (int)t.size();
        string ans = "";
        for (int i=0; i<N; i++) {
            int l=i, r=i;
            for (; l-1 >= 0 && r+1 < N && t[l-1] == t[r+1]; l--, r++);
            if (r-l+1 > (int)ans.size())
                ans = t.substr(l, r-l+1);
        }
        ans.erase(remove(ans.begin(), ans.end(), '#'), ans.end());
        return ans;
    }
};