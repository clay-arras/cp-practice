// https://leetcode.com/problems/button-with-longest-push-time

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int N = (int)events.size();

        int time = events[0][1];
        for (int i=1; i<N; i++) {
            time = max(time, events[i][1] - events[i-1][1]);
        }

        int ind = INT_MAX;
        for (int i=0; i<N; i++) {
            if (i && events[i][1] - events[i-1][1] == time) {
                ind = min(ind, events[i][0]);
            } else if (!i && events[i][1] == time) {
                ind = min(ind, events[i][0]);
            }
        }

        return ind;
    }
};