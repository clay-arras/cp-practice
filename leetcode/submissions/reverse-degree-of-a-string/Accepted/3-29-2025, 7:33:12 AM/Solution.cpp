// https://leetcode.com/problems/reverse-degree-of-a-string

class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int N = (int)s.size();
        for (int i=0; i<N; i++)
            sum += (i+1) * (26 - (s[i]-'a'));
        return sum;
    }
};