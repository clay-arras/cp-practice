// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> p, v;

        int N = (int)s.size();
        for (int i=0; i<N; i++) {
            if (vowels.count(s[i])) {
                v.push_back(s[i]);
                p.push_back(i);
            }
        }
        reverse(v.begin(), v.end());
        int cnt = -1;
        for (int i : p) {
            cnt++;
            s[i] = v[cnt];
        }
        return s;
    }
};