// https://leetcode.com/problems/alice-and-bob-playing-flower-game

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ne = floor(n*1.0/2);
        long long no = ceil(n*1.0/2);
        long long me = floor(m*1.0/2);
        long long mo = ceil(m*1.0/2);

        return ne * mo + no * me;
    }
};