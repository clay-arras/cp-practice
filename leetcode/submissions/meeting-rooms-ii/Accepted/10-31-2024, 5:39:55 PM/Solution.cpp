// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto i : intervals) {
            m[i[0]]++;
            m[i[1]]--;
        }

        int mx = 0, cnt = 0;
        for (auto [k, v] : m) {
            cnt += v;
            mx = max(mx, cnt);
        }
        return mx;
    }
};