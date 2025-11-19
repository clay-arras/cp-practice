// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        int N = (int)s.size();    
        
        set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        string p = s;
        vector<char> rev;
        for (int i=0; i<N; i++) {
            if (vowels.count(p[i])) {
                rev.push_back(p[i]);
            }
        }
        reverse(rev.begin(), rev.end());
        int cnt=0;
        for (int i=0; i<N; i++) {
            if (vowels.count(p[i])) {
                p[i] = rev[cnt++];
            }
        }
        
        return p;
    }
};