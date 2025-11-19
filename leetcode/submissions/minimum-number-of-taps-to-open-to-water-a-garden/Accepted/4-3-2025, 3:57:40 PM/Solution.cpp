// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> segs(n+1);
        for (int i=0; i<n+1; i++) 
            segs[i] = {max(0, i - ranges[i]), -min(n, i + ranges[i])};
        sort(segs.begin(), segs.end());

        if (segs[0].first != 0) return -1;
        int ans = 1, end = -segs[0].second;
        for (int i=0; i<n+1; ) {
            int newEnd = end;
            for (; i < n+1 && segs[i].first <= end; i++) 
                newEnd = max(newEnd, -segs[i].second);
                
            if (end == newEnd) i++;
            else {
                end = newEnd;
                ans++;
            }
        }
        if (end != n) return -1;

        return ans;
    }
};
