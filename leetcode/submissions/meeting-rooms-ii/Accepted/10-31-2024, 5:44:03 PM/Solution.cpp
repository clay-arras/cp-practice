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
        int minYear = -1;
        for (auto [k, v] : m) {
            cnt += v;
            if (cnt > mx) {
                mx = cnt;
                minYear = k;
            }

        }
        return mx;
    }
};