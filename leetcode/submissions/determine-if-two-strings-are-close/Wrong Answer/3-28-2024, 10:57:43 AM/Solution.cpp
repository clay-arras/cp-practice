// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // a) all the letters in word1 are in word2
        // b) they have the same frequencies
        int N = (int)word1.size();
        int M = (int)word2.size();
        if (N != M)
            return false;

        vector<int> l1(26, 0), l2(26, 0);
        for (int i=0; i<N; i++) {
            l1[word1[i] - 'a']++;
            l2[word1[i] - 'a']++;
        }
        set<int> s1, s2;
        for (int i=0; i<26; i++) {
            if ((bool)l1[i] != (bool)l2[i]) 
                return false;
            s1.insert(l1[i]);
            s2.insert(l2[i]);
        }
        return (s1 == s2);
    }
};