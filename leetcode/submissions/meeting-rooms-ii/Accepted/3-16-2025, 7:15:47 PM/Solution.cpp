// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> ends;
        for (auto i : intervals) {
            ends.push_back({i[0], 1});
            ends.push_back({i[1], -1});
        }
        sort(ends.begin(), ends.end());
        
        int count = 0, ans = 0;
        int N = (int)ends.size();
        for (int i=0; i<N; i++) {
            count += ends[i].second;
            ans = max(ans, count);
        }
        
        return ans;
    }
};