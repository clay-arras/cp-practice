// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence

class Solution {
public:
    int appendCharacters(string s, string t) {
        int ptr = 0;
        for (int i=0; i<(int)s.size(); i++)  {
            if (s[i] == t[ptr]) ptr++;
        }

        return (int)t.size() - ptr;
    }
};