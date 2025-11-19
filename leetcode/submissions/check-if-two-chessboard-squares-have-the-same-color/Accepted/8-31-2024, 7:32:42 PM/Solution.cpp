// https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return ((coordinate1[0]-'a'+coordinate1[1]-'1') % 2) == ((coordinate2[0]-'a'+coordinate2[1]-'1') % 2);
    }
};