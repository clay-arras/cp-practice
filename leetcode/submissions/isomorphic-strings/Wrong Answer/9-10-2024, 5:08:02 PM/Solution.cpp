// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> A(26, 0), B(26, 0);
        int N = (int)s.size();
        for (int i=0; i<N; i++) {
            A[s[i]-'a']++;
            B[t[i]-'a']++;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        return A == B;
    }
};