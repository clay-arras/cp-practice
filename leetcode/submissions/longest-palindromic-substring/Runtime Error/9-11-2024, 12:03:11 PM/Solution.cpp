// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) 
            t += string(1, c) + "#";
        int N = (int)t.size();
        t = "$" + t + "%";

        string ans = "";
        int l=1, r=1;
        vector<int> P(N+2);
        for (int i=1; i<=N; i++) {
            P[i] = max(0, min(r-i, P[l+r-i]));
            while (s[i-P[i]] == s[i+P[i]]) P[i]++;
            if (r-l+1 > (int)ans.size())
                ans = t.substr(l, r-l+1);
            if (i + P[i] > r)
                l = i - P[i], r = i + P[i];
        }
        ans.erase(remove(ans.begin(), ans.end(), '#'), ans.end());
        return ans;
    }
};