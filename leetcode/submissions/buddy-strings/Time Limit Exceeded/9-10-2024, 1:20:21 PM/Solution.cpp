// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int N = (int)s.size();
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                swap(s[i], s[j]);
                if (s == goal) return true;
                swap(s[j], s[i]);
            }
        }
        return false;
    }
};