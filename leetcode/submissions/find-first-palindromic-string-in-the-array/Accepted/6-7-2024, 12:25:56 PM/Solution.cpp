// https://leetcode.com/problems/find-first-palindromic-string-in-the-array

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string word : words) {
            string s = word;
            reverse(s.begin(), s.end());
            if (s == word)
                return word;
        }
        return "";
    }
};