// https://leetcode.com/problems/alice-and-bob-playing-flower-game

class Solution {
public:
    long long flowerGame(int n, int m) {
        int ne = floor(n*1.0/2);
        int no = ceil(n*1.0/2);
        int me = floor(m*1.0/2);
        int mo = ceil(m*1.0/2);

        return ne * 1LL * mo + no * me;
    }
};