// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        for (int i=0; i<(int)s.size(); i++) {
            auto a = s.find(' ');
            words.push_back(s.substr(0, a));
            s = s.substr(a+1);
            if (a == string::npos)
                break;
        }
        string s1 = "";
        for (int i=(int)words.size()-1; i>=0; i--) {
            if (words[i] != "")
                s1 += words[i] + " ";
        }
        return s1.substr(0, (int)s1.size()-1);
    }
};