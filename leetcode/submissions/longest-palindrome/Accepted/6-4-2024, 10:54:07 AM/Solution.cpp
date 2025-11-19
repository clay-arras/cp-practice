// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for (char c : s)
            m[c]++;

        int ans = 0;
        bool extra = false;
        for (auto [k, v] : m) {
            extra |= (v % 2);
            ans += v - (v % 2);
        }
        if (extra) ans++;
        return ans;
    }
};