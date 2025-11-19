// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        int N = (int)s.size();
        for (int i=0; i<N/2; i++) {
            int tmp = s[i];
            s[i] = s[N-i-1];
            s[N-i-1] = tmp;
        }
        for (auto i : s)
            cout << i;
    }
};