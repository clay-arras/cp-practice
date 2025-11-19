// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int N = min((int)word1.length(), (int)word2.length());
        for (int i=0; i<N; i++) {
            merged += word1[i] + word2[i];
        }
        if ((int)word1.length() > (int)word2.length()) {
            merged += word1.substr(N);
        } else {
            merged += word2.substr(N);
        }
        return merged;
    }
};