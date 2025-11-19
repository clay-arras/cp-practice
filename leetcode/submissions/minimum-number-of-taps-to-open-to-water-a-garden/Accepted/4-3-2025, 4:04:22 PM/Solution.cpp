// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n+1, -1);
        for (int i=0; i<n+1; i++) 
            maxReach[max(0, i - ranges[i])] = max(maxReach[max(0, i - ranges[i])], min(n, i + ranges[i]));

        if (maxReach[0] == -1) return -1;
        int ans = 1, end = maxReach[0];
        for (int i=0; i<n+1; ) {
            int newEnd = end;
            for (; i <= end; i++) 
                newEnd = max(newEnd, maxReach[i]);

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
