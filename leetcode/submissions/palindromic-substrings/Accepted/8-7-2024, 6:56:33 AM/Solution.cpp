// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        int N = (int)s.size();

        int ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; i+j<N && i-j>=0; j++) {
                if (s[i+j] == s[i-j]) ans++;
                else break;
            }
            for (int j=0; i+j<N && i-j-1>=0; j++) {
                if (s[i+j] == s[i-j-1]) ans++;
                else break;
            }
        }
        return ans;
    }
};