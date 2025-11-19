// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int N = (int)time.size();

        int ans = 0;
        for (int i=0; i<N; i++) {
            ans += m[(60 - time[i] % 60) % 60];
            m[time[i] % 60]++;
        }
        return ans;
    }
};