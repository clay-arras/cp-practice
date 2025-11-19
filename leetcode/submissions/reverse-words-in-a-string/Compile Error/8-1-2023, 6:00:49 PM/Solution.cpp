// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        for (int i=0; i<(int)s.size(); i++) {
            auto a = s.find(' ') - s.begin();
            words.push_back(s.substr(0, a));
            s = s.substr(a+1);
        }
        for (auto i : words)
            cout << i << endl;
        return "";
    }
};