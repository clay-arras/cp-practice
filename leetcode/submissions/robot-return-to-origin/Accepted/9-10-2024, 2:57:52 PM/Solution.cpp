// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        int ud = 0;
        int lr = 0;
        for (char c : moves) {
            if (c == 'R') lr++;
            if (c == 'L') lr--;
            if (c == 'U') ud++;
            if (c == 'D') ud--;
        }
        return (lr == 0 && ud == 0);
    }
};