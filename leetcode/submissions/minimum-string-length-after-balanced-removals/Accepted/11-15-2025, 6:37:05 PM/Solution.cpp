// https://leetcode.com/problems/minimum-string-length-after-balanced-removals

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int N = (int)s.size();  
        unordered_map<char, int> m;
        for (char c : s)
            m[c]++;
        
        return abs(m['a'] - m['b']);
    }
};