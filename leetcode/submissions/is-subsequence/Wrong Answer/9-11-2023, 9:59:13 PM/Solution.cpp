// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int N = (int)s.size(), M = (int)t.size();

        int i, j;
        for (i=0, j=0; i<N and j<M; i++, j++) {
            while (j < M and s[i] != t[j]) {
                j++;
            }
        }
        return (i == N and j == M);
    }
};