// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

class Solution {
public:
    bool winnerOfGame(string colors) {
        map<char, int> m;
        for (int i=1; i<(int)colors.size()-1; i++) {
            if (colors[i-1] == colors[i] && colors[i] == colors[i+1]) 
                m[colors[i]]++;
        }
        return m['A'] > m['B'];
    }
};