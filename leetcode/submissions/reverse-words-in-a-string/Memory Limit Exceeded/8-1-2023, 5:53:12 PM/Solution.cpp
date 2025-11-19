// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        while ((int)s.size()) {
            auto i = s.find(' ');
            words.push_back(s.substr(0, i));
            s = s.substr(i);
        }
        for (auto i : words)
            cout << i << endl;
        return "";
    }
};