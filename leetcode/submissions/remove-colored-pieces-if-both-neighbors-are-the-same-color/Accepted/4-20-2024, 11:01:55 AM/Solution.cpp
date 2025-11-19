// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        int N = (int)colors.size();
        for (int i=1; i<N-1; i++) {
            if (colors[i] == colors[i+1] && colors[i] == colors[i-1]) {
                if (colors[i] == 'A') {
                    a++;
                } else {
                    b++;
                }
            }
        }
        
        return (a > b);
    }
};