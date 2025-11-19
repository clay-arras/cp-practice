// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int N = (int)s.size(), M = (int)t.size();
        if (!N)
            return true;

        int i, j;
        for (i=0, j=0; i<N and j<M; i++, j++) {
            cout << s[i] << t[j] << endl;
            while (j < M and s[i] != t[j]) {
                j++;
            }
            cout << s[i] << t[j] << endl;
        }
        cout << i << j << endl;
        return (s[i-1] == t[j-1]);
    }
};