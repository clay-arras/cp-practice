// https://leetcode.com/problems/break-a-palindrome

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = (int)palindrome.size();
        for (char c='a'; c<='z'; c++) {
            for (int i=0; i<N; i++) {
                if (palindrome[i] > c && i != N/2 && N % 2) {
                    palindrome[i] = c;
                    return palindrome;
                }
            }
        }
        return "";
    }
};