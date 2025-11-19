// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());

        int N = (int)s.size();
        int count = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == ' ' && count)
                break;
            if (s[i] != ' ')
                count++;
        }
        return count;
    }
};