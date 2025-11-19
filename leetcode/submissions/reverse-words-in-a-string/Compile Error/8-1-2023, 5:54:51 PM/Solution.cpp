// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        auto i = s.find(' ');
        while ((i = s.find(' ') != s.end())) {
            words.push_back(s.substr(0, i));
            s = s.substr(i+1);
        }
        for (auto i : words)
            cout << i << endl;
        return "";
    }
};