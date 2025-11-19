// https://leetcode.com/problems/walking-robot-simulation

class Solution {
public:
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int, int>, bool> m;
        for (auto i : obstacles) 
            m[{i[0], i[1]}] = true;
        
        int ans = 0, ptr = 0;
        int x = 0, y = 0;
        for (int i : commands) {
            if (i == -1) {
                ptr = (ptr + 1) % 4;
            } else if (i == -2) {
                ptr = (ptr + 3) % 4;
            } else {
                for (int k=1; k<=i; k++) {
                    int nx = x + dx[ptr];
                    int ny = y + dy[ptr];
                    if (m[{nx, ny}])
                        break;
                    x = nx;
                    y = ny;
                }
            }
            ans = max(ans, x*x + y*y);
        }
        return ans;
    }
};