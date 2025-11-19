// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        while ((s.find(' ') != s.end())) {
            auto i = s.find(' ');
            words.push_back(s.substr(0, i));
            s = s.substr(i+1);
        }
        for (auto i : words)
            cout << i << endl;
        return "";
    }
};